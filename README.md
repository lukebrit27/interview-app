# Interview App

The Interview App is a command-line application that conducts interviews by asking a series of questions from a Markdown file. It provides flexibility in specifying the number of questions per category and allows customization of the Markdown file to suit your interview needs.

## Background
I created this app as a fun way to learn C++ while also creating a practical a tool I could use to practice for interviews. Hope you find it interesting!

## Features

- Loads interview questions from a Markdown file.
- Conducts interviews by asking questions from different categories.
- Supports specifying the number of questions per category.
- Provides default values for the number of questions (10) if not explicitly specified.
- Displays questions and allows users to show answers interactively.

## Requirements

- C++11 compatible compiler
- CMake (version 3.12 or higher)
- Markdown file containing interview questions

## Installation

1. Clone the repository or download the source code.
2. Navigate to the project directory.

## Usage

To use the Interview App, follow these steps:

1. Create a Markdown file containing your interview questions. The file should follow the specified format.
2. Build the Interview App using CMake:

   ```shell
   cmake .
   make
   ```

3. Run the application:

   ```shell
   ./interview-app -f <path-to-markdown-file> -c <category1> <num-questions1> -c <category2> <num-questions2> ...
   ```

   Replace `<path-to-markdown-file>` with the path to your Markdown file.
   Replace `<category>` with the desired category name.
   Replace `<num-questions>` with the number of questions you want to ask for each category. If not specified, a default value will be used.

   Example:

   ```shell
   ./bin/interview-app -f data/InterviewQuestions.md -c kdb 5 -c general 10
   ```

   This command will load questions from the `data/InterviewQuestions.md` file and ask 5 questions from the "kdb" category and 10 questions from the "general" category.

4. Follow the prompts and interact with the application to answer the questions.

## Markdown File Format

The Markdown file used by the Interview App should follow a specific format. Here's an example:

```markdown
# Category 1
* Question 1
   * Answer 1 
* Question 2
   * Answer 2 

# Category 2
* Question 3
   * Answer 3  
* Question 4
   * Answer 4    
* Question 5
   * Answer 5
```

Each category should be denoted by a single `#` character followed by the category name. Each question within a category should start with a `*` character. Each answer within a question should be indented by at least 1 space. Answers can be multiple lines as long they are indented.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please let me know.

## License

This project is licensed under the [MIT License](LICENSE).

---

Feel free to customize the README file according to your specific project requirements and preferences.
