 internal class BubbleSort
    {     
            static void Main(string[] args)
            {
                int[] number = { 83, 70, 38, 125, 68, 15, 110 };
                bool flag = true;
                int temp;
                int numLength = number.Length;
                        
            //sorting an array
            for (int i = 1; (i <= (numLength - 1)) && flag; i++)
                {
                    flag = false;
                    for (int j = 0; j < (numLength - 1); j++)
                    {
                        if (number[j + 1] > number[j])
                        {
                            temp = number[j];
                            number[j] = number[j + 1];
                            number[j + 1] = temp;
                            flag = true;
                        }
                    }
                }          
            Console.Write("Sorted numbers\t");
            //Sorted array
            foreach (int num in number)
                {              
                    Console.Write("\t {0}", num);
                }
                Console.Read();
            }
        }
