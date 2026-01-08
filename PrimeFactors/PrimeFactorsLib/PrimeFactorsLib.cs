namespace PrimeFactors;

public class PrimeFactorsLib
{
    string factors = "";

    /// <summary>
    /// Determines all the prime factors in a given number (accurate up to 1000)
    /// </summary>
    /// <param name="number">Integer to find all prime factors of</param>
    /// <returns>String of all prime factors.</returns>
    public string PrimeFactors(int number)
    {
        // Divide number by smallest prime number
        for (int i = 2; i <= 1_000; i++)
        {
            if (number % i != 0)
            {
                continue;
            }
            else if (number != 1)
            {
                factors += $"{i} ";
                number = number / i;
                PrimeFactors(number);
            }

            return factors;
        }

        return factors;
    }
}
