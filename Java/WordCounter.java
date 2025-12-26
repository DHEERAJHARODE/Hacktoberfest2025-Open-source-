import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.stream.*;

public class WordCounter {
    public static void main(String[] args) throws IOException {
        Path filePath = Path.of("sample.txt");

        if (!Files.exists(filePath)) {
            System.out.println("File not found: " + filePath.toAbsolutePath());
            return;
        }

        String text = Files.readString(filePath);

        Map<String, Long> wordFreq = Arrays.stream(text.split("\\W+"))
                .filter(w -> !w.isBlank()) 
                .map(String::toLowerCase)
                .collect(Collectors.groupingBy(w -> w, Collectors.counting()));

        System.out.println("Word frequencies:");
        wordFreq.forEach((word, count) -> 
            System.out.println(word + " -> " + count));
    }
}
