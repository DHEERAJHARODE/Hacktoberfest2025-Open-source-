public class ComplexNumberMultiplication {

    static class ComplexNumber {
        double real;
        double imaginary;

        public ComplexNumber(double real, double imaginary) {
            this.real = real;
            this.imaginary = imaginary;
        }

        public ComplexNumber multiply(ComplexNumber other) {
            double realPart = this.real * other.real - this.imaginary * other.imaginary;
            double imaginaryPart = this.real * other.imaginary + this.imaginary * other.real;
            return new ComplexNumber(realPart, imaginaryPart);
        }

        public ComplexNumber add(ComplexNumber other) {
            return new ComplexNumber(this.real + other.real, this.imaginary + other.imaginary);
        }

        public ComplexNumber subtract(ComplexNumber other) {
            return new ComplexNumber(this.real - other.real, this.imaginary - other.imaginary);
        }

        @Override
        public String toString() {
            if (imaginary >= 0) {
                return String.format("%.2f + %.2fi", real, imaginary);
            } else {
                return String.format("%.2f - %.2fi", real, Math.abs(imaginary));
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("Complex Number Operations");
        System.out.println("========================");

        ComplexNumber num1 = new ComplexNumber(3, 4);
        ComplexNumber num2 = new ComplexNumber(1, 2);

        System.out.println("First complex number: " + num1);
        System.out.println("Second complex number: " + num2);
        System.out.println();

        ComplexNumber product = num1.multiply(num2);
        System.out.println("Multiplication: " + product);

        ComplexNumber sum = num1.add(num2);
        System.out.println("Addition: " + sum);

        ComplexNumber difference = num1.subtract(num2);
        System.out.println("Subtraction: " + difference);

        System.out.println();
        System.out.println("Additional test cases:");

        ComplexNumber[] testNumbers = {
            new ComplexNumber(2, 3),
            new ComplexNumber(-1, 5),
            new ComplexNumber(0, 2),
            new ComplexNumber(4, 0)
        };

        for (int i = 0; i < testNumbers.length - 1; i++) {
            ComplexNumber a = testNumbers[i];
            ComplexNumber b = testNumbers[i + 1];
            ComplexNumber result = a.multiply(b);
            System.out.println(a + " * " + b + " = " + result);
        }
    }
}