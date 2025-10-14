import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class MemoryGame extends JFrame implements ActionListener {
    private final int GRID_SIZE = 4; // 4x4 grid = 8 pairs
    private JButton[] buttons;
    private String[] icons;
    private boolean[] matched;
    private JButton firstButton = null;
    private JButton secondButton = null;
    private Timer timer;
    private int pairsFound = 0;

    public MemoryGame() {
        setTitle("🧩 Memory Puzzle Game");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(GRID_SIZE, GRID_SIZE));
        setSize(500, 500);

        buttons = new JButton[GRID_SIZE * GRID_SIZE];
        matched = new boolean[GRID_SIZE * GRID_SIZE];
        icons = generateIcons();

        for (int i = 0; i < buttons.length; i++) {
            buttons[i] = new JButton("?");
            buttons[i].setFont(new Font("Arial", Font.BOLD, 30));
            buttons[i].addActionListener(this);
            add(buttons[i]);
        }

        setVisible(true);
    }

    private String[] generateIcons() {
        // Simple icons represented by emojis or letters
        String[] base = {"🍎", "🍌", "🍇", "🍒", "🍓", "🍍", "🥝", "🍉"};
        List<String> pairs = new ArrayList<>();
        for (String s : base) {
            pairs.add(s);
            pairs.add(s);
        }

        Collections.shuffle(pairs);
        return pairs.toArray(new String[0]);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton clicked = (JButton) e.getSource();

        int index = Arrays.asList(buttons).indexOf(clicked);
        if (matched[index] || clicked == firstButton) return;

        clicked.setText(icons[index]);

        if (firstButton == null) {
            firstButton = clicked;
        } else {
            secondButton = clicked;

            // Disable input while checking
            for (JButton b : buttons) b.setEnabled(false);

            timer = new Timer(800, new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    checkMatch();
                }
            });
            timer.setRepeats(false);
            timer.start();
        }
    }

    private void checkMatch() {
        int firstIndex = Arrays.asList(buttons).indexOf(firstButton);
        int secondIndex = Arrays.asList(buttons).indexOf(secondButton);

        if (icons[firstIndex].equals(icons[secondIndex])) {
            matched[firstIndex] = true;
            matched[secondIndex] = true;
            pairsFound++;
            firstButton.setEnabled(false);
            secondButton.setEnabled(false);

            if (pairsFound == icons.length / 2) {
                JOptionPane.showMessageDialog(this, "🎉 You matched all pairs!", "Game Over", JOptionPane.INFORMATION_MESSAGE);
            }
        } else {
            firstButton.setText("?");
            secondButton.setText("?");
        }

        firstButton = null;
        secondButton = null;

        for (JButton b : buttons) {
            if (!b.getText().equals("?") || !b.isEnabled()) continue;
            b.setEnabled(true);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(MemoryGame::new);
    }
}
