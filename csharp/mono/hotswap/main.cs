using System;
using System.IO;
using System.Reflection;

namespace HotSwapTest {
    class HotSwapTest {
        static void Main(string[] args) {

            // int interval = 180000;  // 3分钟后更新代码
            // int sum_interval = 0;

            // 加载基础模块
            AppDomainSetup common_domain_info = new AppDomainSetup();
            Console.WriteLine("common_domain_info dynamic path {0}", common_domain_info.DynamicBase);
            // string path = AppDomain.CurrentDomain.BaseDirectory;
            common_domain_info.ApplicationName = "HotSwapTest";
            common_domain_info.LoaderOptimization = LoaderOptimization.SingleDomain;
            // common_domain_info.DynamicBase = path;
            // Console.WriteLine("common_domain_info dynamic path {0}", common_domain_info.DynamicBase);
            // common_domain_info.ApplicationBase = path;
            // Console.WriteLine("common_domain_info app base {0}", common_domain_info.ApplicationBase);

            AppDomain common_domain = AppDomain.CreateDomain("CommonDomain", null, common_domain_info);
            // common_domain.ExecuteAssembly("common.exe");
            common_domain.Load(args[0]);
            // try {
                // common_domain.Load("common.dll");
            // Assembly a = Assembly.Load("hotswatpcommon.dll");
            // } catch(FileNotFoundException e) {
            //    Console.WriteLine("error filename ''''{0}''''", e.FileName);
            // }

            // object obj = common_domain.CreateInstanceAndUnwrap("common.exe", "HotSwap.CommonTest");

            // sleeping for a while
            // while (true) {
            //     int loop_interval = obj.
            //     Console.WriteLine("Time now {0}", DateTime.Now);
            //     Console.WriteLine("Start to get sleep time {0}", loop_interval);

            //     System.Threading.Thread.Sleep(loop_interval);
            //     break;
            // }
        }
    };
}
