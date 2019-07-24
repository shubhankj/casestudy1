using System.Linq;
using System;
using System.Runtime.CompilerServices;
using NDepend;
using NDepend.Analysis;
using NDepend.Path;
using NDepend.PowerTools;
using NDepend.Project;

namespace YourNamespace
{
    class Program
    {

        // ************************** IMPORTANT ***********************************
        // All programs using NDepend.API.dll should have this type AssemblyResolver
        // parametrized with the relative path to the dir "$NDependInstallDir$\Lib".
        // Since  NDepend.PowerTool.exe  is in the dir "$NDependInstallDir$"
        // the relative path is @".\Lib"
        private static readonly AssemblyResolver s_AssemblyResolver = new AssemblyResolver(@".\Lib");

        [STAThread]
        static void Main()
        {
            AppDomain.CurrentDomain.AssemblyResolve += s_AssemblyResolver.AssemblyResolveHandler;
            MainSub();
        }

        // Need this MethodImplAttribute to make sure that AssemblyResolve
        // has been registered successfully before JITing any method
        // that uses anything from the NDepend.API
        [MethodImpl(MethodImplOptions.NoInlining)]
        static void MainSub()
        {
            var ndependServicesProvider = new NDependServicesProvider();

            // Example of using the NDepend.API
            var projectManager = ndependServicesProvider.ProjectManager;
            IProject project = projectManager.LoadProject(@"C:\YourPathToYourNDependProjectFile\File.ndproj".ToAbsoluteFilePath());

            // Try to load the most recent analysis result
            var refs = project.GetAvailableAnalysisResultsRefs();
            if (!refs.Any()) { return; }
            IAnalysisResult result = refs[0].Load();

            // Obtain source files paths from the analysis result code base model (for example)
            var sourceFiles = result.CodeBase.Application.CodeElements
               .Where(c => c.SourceFileDeclAvailable)
               .SelectMany(c => c.SourceDecls)
               .Select(c => c.SourceFile.FilePath)
               .Distinct()
               .ToList();

            // Print all source files paths
            foreach (IAbsoluteFilePath sourceFilePath in sourceFiles)
            {
                Console.WriteLine(sourceFilePath.ToString());
            }
        }
    }
}