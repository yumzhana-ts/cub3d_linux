import os
import re

def extract_prototypes_from_source(source_file):
    """
    Extract function prototypes from a C source file.

    Args:
        source_file (str): Path to the C source file.

    Returns:
        list: List of function prototypes.
    """
    prototypes = []
    try:
        with open(source_file, 'r') as file:
            content = file.read()
            # Regex pattern to match function prototypes
            pattern = re.compile(r'^[a-zA-Z_]\w*\s+[a-zA-Z_]\w*\s*\([^)]*\)\s*(?=[{;])', re.MULTILINE)
            matches = pattern.findall(content)
            prototypes.extend(matches)
    except Exception as e:
        print(f"Error reading {source_file}: {e}")
    return prototypes

def append_to_header_file(header_file, prototypes):
    """
    Append function prototypes to the header file.

    Args:
        header_file (str): Path to the header file.
        prototypes (list): List of function prototypes.
    """
    try:
        with open(header_file, 'a') as file:
            file.write('\n// Additional prototypes\n')
            for proto in prototypes:
                file.write(proto + ';\n')
    except Exception as e:
        print(f"Error writing to {header_file}: {e}")

def process_all_c_files(directory, header_file):
    """ 
    Process all C source files in a directory to append prototypes to a header file.

    Args:
        directory (str): Path to the directory containing C source files.
        header_file (str): Path to the header file to update.
    """
    all_prototypes = set()  # Use a set to avoid duplicates
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith('.c'):
                file_path = os.path.join(root, file)
                prototypes = extract_prototypes_from_source(file_path)
                all_prototypes.update(prototypes)
    append_to_header_file(header_file, sorted(all_prototypes))

# Example usage
source_directory = 'src'  # Directory containing your .c files
header_file = 'headers/cub3d.h'  # Your header file to append to
process_all_c_files(source_directory, header_file)
