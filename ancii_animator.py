import math
import time
import os

def clear_screen():
    """Clear the terminal screen"""
    os.system('cls' if os.name == 'nt' else 'clear')

def generate_wave_pattern(width, height, time_offset, wave_type='sine'):
    """Generate an ASCII wave pattern"""
    chars = ' .:-=+*#%@'
    pattern = []
    
    for y in range(height):
        row = []
        for x in range(width):
            # Create multiple wave frequencies
            if wave_type == 'sine':
                val1 = math.sin(x * 0.1 + time_offset)
                val2 = math.sin(y * 0.2 + time_offset * 1.5)
                val3 = math.cos(math.sqrt((x-width/2)**2 + (y-height/2)**2) * 0.1 - time_offset)
            elif wave_type == 'ripple':
                dist = math.sqrt((x - width/2)**2 + (y - height/2)**2)
                val1 = math.sin(dist * 0.3 - time_offset * 2)
                val2 = math.cos(dist * 0.2 + time_offset)
                val3 = math.sin(x * 0.05 + y * 0.05)
            else:  # 'plasma'
                val1 = math.sin(x * 0.08 + time_offset)
                val2 = math.sin(y * 0.08 + time_offset * 0.7)
                val3 = math.sin((x + y) * 0.06 + time_offset * 1.3)
            
            # Combine waves
            combined = (val1 + val2 + val3) / 3
            
            # Map to character
            idx = int((combined + 1) * (len(chars) - 1) / 2)
            idx = max(0, min(len(chars) - 1, idx))
            row.append(chars[idx])
        
        pattern.append(''.join(row))
    
    return pattern

def print_pattern(pattern, title):
    """Print the pattern with a title"""
    print(f"\n{'='*len(pattern[0])}")
    print(f"{title.center(len(pattern[0]))}")
    print(f"{'='*len(pattern[0])}\n")
    for row in pattern:
        print(row)
    print(f"\n{'='*len(pattern[0])}")

def main():
    width = 80
    height = 24
    
    patterns = [
        ('sine', 'SINE WAVE INTERFERENCE'),
        ('ripple', 'RIPPLE EFFECT'),
        ('plasma', 'PLASMA FIELD')
    ]
    
    print("\n🌊 ASCII WAVE PATTERN ANIMATOR 🌊\n")
    print("Watch the mesmerizing patterns flow!")
    print("Press Ctrl+C to exit\n")
    time.sleep(2)
    
    try:
        t = 0
        pattern_idx = 0
        frames_per_pattern = 50
        frame_count = 0
        
        while True:
            wave_type, title = patterns[pattern_idx]
            pattern = generate_wave_pattern(width, height, t, wave_type)
            
            clear_screen()
            print_pattern(pattern, title)
            print(f"\nFrame: {frame_count + 1} | Pattern {pattern_idx + 1}/{len(patterns)}")
            print("Press Ctrl+C to exit")
            
            time.sleep(0.05)
            t += 0.15
            frame_count += 1
            
            # Switch patterns
            if frame_count >= frames_per_pattern:
                frame_count = 0
                pattern_idx = (pattern_idx + 1) % len(patterns)
                time.sleep(1)  # Pause between patterns
                
    except KeyboardInterrupt:
        clear_screen()
        print("\n✨ Thanks for watching the waves! ✨\n")

if __name__ == "__main__":
    main()