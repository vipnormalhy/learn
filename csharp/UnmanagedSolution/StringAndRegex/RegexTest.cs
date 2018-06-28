using System;
using System.Text.RegularExpressions;

namespace StringAndRegex.RegexTest {
	class RegexTest {
		public const string text = @"We publish source for the engine in several branches:

The release branch is extensively tested by our QA team and makes a great starting point for learning the engine or making your own games. We work hard to make releases stable and reliable, and aim to publish new releases every few months.

The promoted branch is updated with builds for our artists and designers to use. We try to update with merges from the master branch daily (though we often catch things that prevent us from doing so) and it's a good balance between getting the latest cool stuff and knowing most things work.

The master branch is the hub of changes from all our specialized engine development teams. Our internal game teams typically take engine snapshots from here, but it isn't subject to as much testing as release branches.

Individual teams have their own development branches for day to day work (dev-core, dev-mobile and dev-sequencer, for example). These branches reflect the cutting edge of the engine and may be buggy - they may not even compile. Battle-hardened developers eager to test new features or work lock-step with us should head to one of these. We aim to merge development branches to master every 3-4 weeks.

Other short-lived branches may pop-up from time to time as we stabilize new releases or hotfixes.";

		public const string iptext = @"fasdfasdf192.168.21.3asdnlkjanfj283.382.134.4afncakjn123.234.134,4";

		public void Test() {
			int wordnum = CountWord();
			Console.WriteLine($"word num is {wordnum}");
			findip();
		}

		int CountWord() {
			string regular = @"\b\S*\b";
			MatchCollection matches = Regex.Matches(text, regular, RegexOptions.ExplicitCapture);

			int num = 0;
			foreach (Match data in matches) {
				// Console.WriteLine(data.Index);
				Console.WriteLine(data.ToString());
				num += 1;
			}
			return num;
		}

		void findip() {
			string regular = @"(\d+)\.(\d+)\.(\d+)\.(\d+)";
			Regex ip_reg = new Regex(regular);

			MatchCollection matches = ip_reg.Matches(iptext);
			foreach (Match match in matches) {
				foreach (Group gp in match.Groups) {
					if (gp.Success) {
						Console.WriteLine($"find group {gp.Index}, {gp.Value}");
					} else {
						Console.WriteLine("group not success");
					}
				}
			}
		}
	}
}
