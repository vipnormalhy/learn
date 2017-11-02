using System;

namespace HotSwapTest {
    class CommonTest {
        public int sleep_interval = 0;

        public int GetSleepTime() {
            if (sleep_interval == 0) {
                sleep_interval = 1;
                return 5;
            } else {
                sleep_interval = 0;
                return 1;
            }
        }
        static void Main() {
            Console.WriteLine("iuiuiuiuiuiuiuiuiiuiuiu");
        }
    }
}
