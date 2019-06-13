using System;


namespace Review_Final_CSharp
{

    

    class main
    {

        const string ASTERISK = "************************";
        const int ARR_SIZE = 5;
        const int RAN_MAX = 50;
        const int RAN_MIN = 1;



        static void Main(string[] args)
        {
            Random rand = new Random();

            Console.WriteLine(ASTERISK + "This is C# review for cpsc 3200" + ASTERISK);
            //TestOverLoadedOperators();
            TestSequence(rand);

            Console.ReadLine();
        }


        public static void TestOverLoadedOperators()
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "Begin Test Overloaded Operator" + ASTERISK);
            Console.WriteLine("");

            Box b1 = new Box();
            Box b2 = new Box();
            Box b3 = new Box();

            Console.WriteLine("");
            b1.SetBreadth(2.0);
            b1.SetHeight(2.0);
            b1.SetLength(2.0);
            Console.WriteLine("Display box1 dimensions: {0}", b1);
            Console.WriteLine("Display box1 volume: {0}", b1.GetVolume());

            Console.WriteLine("");
            b2.SetBreadth(3.0);
            b2.SetHeight(3.0);
            b2.SetLength(3.0);
            Console.WriteLine("Display box2 dimensions: {0}", b2);
            Console.WriteLine("Display box2 volume: {0}", b2.GetVolume());

            Console.WriteLine("");
            b3 = b1 + b2;
            Console.WriteLine("Add box1 + box2 = {0}", b3);
            Console.WriteLine("Display box3 volume: {0}", b3.GetVolume());

            Console.WriteLine("");
            b3 = b2 + b1; //same result as b1 + b2
            Console.WriteLine("Add box2 + box1 = {0}", b3);
            Console.WriteLine("Display box3 volume: {0}", b3.GetVolume());

            Console.WriteLine("");
            b3 = b1 + 9; //same result as b1 + b2
            Console.WriteLine("Add box1 + 9 = {0}", b3);
            Console.WriteLine("Display box3 dimensions: {0}", b3);



            Console.WriteLine("");
            Console.WriteLine("Compare box1 > box2 --> {0}", (b1 > b2) ? "Yes" : "No");
            Console.WriteLine("Compare box1 < box2 --> {0}", (b1 < b2) ? "Yes" : "No");

            Console.WriteLine("");
            Console.WriteLine("Compare box1 <= box2 --> {0}", (b1 <= b2) ? "Yes" : "No");
            Console.WriteLine("Compare box1 >= box2 --> {0}", (b1 >= b2) ? "Yes" : "No");
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "End Test Overloaded Operator" + ASTERISK);
          

        }

        public static void TestSequence(Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "Begin Test Sequence" + ASTERISK);
            Console.WriteLine("");

            int[] arrSeq = new int[ARR_SIZE];
            int num;

            Console.WriteLine("Numbers passed to Sequence class");
            for (int i = 0; i < ARR_SIZE; i++)
            {
                num = rand.Next(RAN_MIN, RAN_MAX);
                Console.Write("{0},", num);
                arrSeq[i] = num;
            }

          
            uint num1 = (uint)rand.Next(RAN_MIN, RAN_MAX);
            uint num2 = (uint)rand.Next(RAN_MIN, RAN_MAX);
            Console.WriteLine("");
            Console.WriteLine("x = {0}, y = {1}", num1, num2);

            Sequence mySequence = new Sequence(arrSeq, num1, num2);

            for (int i = 0; i < ARR_SIZE * 2; i++)
            {
                num = rand.Next(RAN_MIN, RAN_MAX);
                mySequence.Ping(num );
                Console.WriteLine(i + 1 + ") Ping value {0}", num);
            }
            Console.WriteLine("");
            Console.WriteLine("Printing ping stats...");
            Console.WriteLine("- Max ping {0}", mySequence.GetMaxPing());
            Console.WriteLine("- Min ping {0}", mySequence.GetMinPing());
            Console.WriteLine("- Ping count {0}", mySequence.GetPingCount());
            Console.WriteLine("- Ping sum {0}", mySequence.GetSumPing());

            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "End Test Sequence" + ASTERISK);
        }
    }
}
