//Compress A file using Huffman Coding Algorithm
import java.io.*;
import java.util.*;

//Here is the properties of the Huffman Node
class HuffmanNode implements Comparable<HuffmanNode> {
    char character;
    int frequency;
    HuffmanNode left, right;

    public int compareTo(HuffmanNode node) {
        return frequency - node.frequency;
    }
}

class Compress_File {
    private static Map<Character, String> huffmanCodes;

    
    public static void compressFile(String sourceFile, String compressedFile) {
        Map<Character, Integer> frequencyMap = getFrequencyMap(sourceFile);
        HuffmanNode rootNode = buildHuffmanTree(frequencyMap);
        huffmanCodes = new HashMap<>();
        generateHuffmanCodes(rootNode, new StringBuilder());
        writeCompressedFile(sourceFile, compressedFile);
    }

    //Building  the frequency map 
    private static Map<Character, Integer> getFrequencyMap(String sourceFile) {
        Map<Character, Integer> frequencyMap = new HashMap<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(sourceFile))) {
            int ch;
            while ((ch = reader.read()) != -1) {
                char character = (char) ch;
                frequencyMap.put(character, frequencyMap.getOrDefault(character, 0) + 1);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return frequencyMap;
    }

    //Building Huffman Tree for the input file

    private static HuffmanNode buildHuffmanTree(Map<Character, Integer> frequencyMap) {
        PriorityQueue<HuffmanNode> priorityQueue = new PriorityQueue<>();
        for (Map.Entry<Character, Integer> entry : frequencyMap.entrySet()) {
            HuffmanNode node = new HuffmanNode();
            node.character = entry.getKey();
            node.frequency = entry.getValue();
            node.left = null;
            node.right = null;
            priorityQueue.add(node);
        }

        while (priorityQueue.size() > 1) {
            HuffmanNode leftNode = priorityQueue.poll();
            HuffmanNode rightNode = priorityQueue.poll();
            HuffmanNode parentNode = new HuffmanNode();
            parentNode.frequency = leftNode.frequency + rightNode.frequency;
            parentNode.left = leftNode;
            parentNode.right = rightNode;
            priorityQueue.add(parentNode);
        }
        return priorityQueue.poll();
    }

    //Building Huffman Node for the Huffman Tree
    private static void generateHuffmanCodes(HuffmanNode node, StringBuilder code) {
        if (node == null) {
            return;
        }

        if (node.left == null && node.right == null) {
            huffmanCodes.put(node.character, code.toString());
        }

        code.append('0');
        generateHuffmanCodes(node.left, code);
        code.deleteCharAt(code.length() - 1);

        code.append('1');
        generateHuffmanCodes(node.right, code);
        code.deleteCharAt(code.length() - 1);
    }

    //Writing into the output file(compressed file)
    private static void writeCompressedFile(String sourceFile, String compressedFile) {
        try (BufferedReader reader = new BufferedReader(new FileReader(sourceFile));
             DataOutputStream outputStream = new DataOutputStream(new FileOutputStream(compressedFile))) {
            StringBuilder compressedData = new StringBuilder();
            int ch;
            while ((ch = reader.read()) != -1) {
                char character = (char) ch;
                compressedData.append(huffmanCodes.get(character));
            }

            int padding = 8 - (compressedData.length() % 8);
            for (int i = 0; i < padding; i++) {
                compressedData.append('0');
            }

            byte[] compressedBytes = new byte[compressedData.length() / 8];
            for (int i = 0; i < compressedData.length(); i += 8) {
                String byteString = compressedData.substring(i, i + 8);
                byte compressedByte = (byte) Integer.parseInt(byteString, 2);
                compressedBytes[i / 8] = compressedByte;
            }

            outputStream.write(padding);
            outputStream.write(compressedBytes);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        String sourceFile = "input.txt";
        String compressedFile = "compressed.bin";
        Compress_File.compressFile(sourceFile, compressedFile);
        System.out.println("File compressed successfully!");
    }
}
//Contributed by PRAYAS