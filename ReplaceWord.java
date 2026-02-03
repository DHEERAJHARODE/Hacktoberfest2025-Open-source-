import java.util.Scanner;

class ReplaceWord {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String sentence, word, replacement;

        System.out.println("Enter the string:");
        sentence = scanner.nextLine();

        System.out.println("Enter the word to be searched:");
        word = scanner.nextLine();

        System.out.println("Enter the word to be replaced:");
        replacement = scanner.nextLine();

        String replacedSentence = sentence.replace(word, replacement);

        if (replacedSentence.equals(sentence)) {
            System.out.println("The word " + word + " not found");
        } else {
            System.out.println(replacedSentence);
        }
    }
}
