from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas

def text_to_pdf(input_file, output_file):
    # Create a new PDF document
    c = canvas.Canvas(output_file, pagesize=letter)
    
    # Read text from the input file and write it to the PDF
    with open(input_file, 'r', encoding='utf-8') as file:
        lines = file.readlines()
        y_position = 700  # Set the initial y-coordinate position
        line_height = 12  # Height between lines in points
        
        for line in lines:
            # Write the line to the PDF
            c.drawString(50, y_position, line.strip())
            # Update the y-coordinate position for the next line
            y_position -= line_height
    
    # Save the PDF file
    c.save()

# Example usage
input_text_file = 'input.txt'  # Replace 'input.txt' with your input text file
output_pdf_file = 'output.pdf'  # Replace 'output.pdf' with the desired output PDF file name

text_to_pdf(input_text_file, output_pdf_file)
#Contributed by Sumit Awate
