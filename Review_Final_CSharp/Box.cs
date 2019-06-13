/*
 &&, ||
The conditional logical operators cannot be overloaded directly.

	
=, ., ?:, ->, new, is, sizeof, typeof
These operators cannot be overloaded

 */

using System;


namespace Review_Final_CSharp
{
    class Box
    {
        //private data members
        private double length; //length of a box
        private double breath; //breath of a box
        private double height; //height of a box

        public Box() { } //constructor

        public double GetVolume()
        {
            return height * breath * length;
        }

        public void SetLength(double len)
        {
            length = len;
        }

        public void SetBreadth (double bre)
        {
            breath = bre;
        }

        public void SetHeight (double hei)
        {
            height = hei;
        }

        ///////////////////////////////OVERLOADED OPERATORS//////////////////////////////////
        //Overloaded + operator to add two Box objects
        public static Box operator+(Box b, Box c)
        {
            Box box = new Box();
            box.length = b.length + c.length;
            box.height = b.height + c.height;
            box.breath = b.breath + c.breath;

            return box; //a third box
        }

        public static Box operator+(Box b, int k)
        {
            Box box = new Box();
            box.length = b.length + k;
            box.height = b.height + k;
            box.breath = b.breath + k;

            return box; 
        }

        //Overloaded == operator to compare 2 box objects
        // == operator must have a matching != operator
        public static bool operator==(Box lhs, Box rhs)
        {
            //bool status = false;

            //if (lhs.breath == rhs.breath && lhs.height == rhs.height && lhs.length == rhs.length)
            //{
            //    status = true;
            //}

            return !(lhs!=rhs);
        }


        public static bool operator!= (Box lhs, Box rhs)
        {
            bool status = false;
            if (lhs.breath != rhs.breath && lhs.height != rhs.height && lhs.length != rhs.length)
            {
                status = true;
            }
            return status;
        }

        // < operator requires a matching operator for > operator
        public static bool operator<(Box lhs, Box rhs)
        {
            bool status = false;
             if (lhs.breath < rhs.breath && lhs.height < rhs.height && lhs.length < rhs.length)
            {
                status = true;
            }

            return status;

        }

        public static bool operator>(Box lhs, Box rhs)
        {
            bool status = false;
            if (lhs.breath > rhs.breath && lhs.height > rhs.height && lhs.length > rhs.length)
            {
                status = true;
            }

            return status;
        }

        // <= operator must match a >= operator
        public static bool operator <= (Box lhs, Box rhs)
        {
            bool status = false;
            if (lhs.breath <= rhs.breath && lhs.height <= rhs.height && lhs.length <= rhs.length)
            {
                status = true;
            }

            return status;
        }

        public static bool operator >= (Box lhs, Box rhs)
        {
            bool status = false;
            if (lhs.breath >= rhs.breath && lhs.height >= rhs.height && lhs.length >= rhs.length)
            {
                status = true;
            }

            return status;
        }

        //OVERLOADED ToString
        public override string ToString()
        {
            return String.Format("Length {0}, Breadth {1}, Height {2}", length, breath, height);
        }
    }
}
