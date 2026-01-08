namespace PrimeFactors;

public class PrimeFactorsLibUnitTest
{
    [Fact]
    public void Test1()
    {
        // arrange
        int a = 10;
        string expected = "2 5 ";
        PrimeFactorsLib factor = new();

        // act
        string actual = factor.PrimeFactors(a);

        // assert
        Assert.Equal(expected, actual);
    }

    [Fact]
    public void Test2()
    {
        // arrange
        int a = 7;
        string expected = "7 ";
        PrimeFactorsLib factor = new();

        // act
        string actual = factor.PrimeFactors(a);

        // assert
        Assert.Equal(expected, actual);
    }

    [Fact]
    public void Test3()
    {
        // arrange
        int a = 40;
        string expected = "2 2 2 5 ";
        PrimeFactorsLib factor = new();

        // act
        string actual = factor.PrimeFactors(a);

        // assert
        Assert.Equal(expected, actual);
    }
}