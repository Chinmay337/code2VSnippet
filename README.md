```
███████╗████████╗██████╗       ███████╗███╗   ██╗██╗██████╗ ██████╗ ███████╗████████╗
██╔════╝╚══██╔══╝██╔══██╗      ██╔════╝████╗  ██║██║██╔══██╗██╔══██╗██╔════╝╚══██╔══╝
███████╗   ██║   ██████╔╝█████╗███████╗██╔██╗ ██║██║██████╔╝██████╔╝█████╗     ██║
╚════██║   ██║   ██╔══██╗╚════╝╚════██║██║╚██╗██║██║██╔═══╝ ██╔═══╝ ██╔══╝     ██║
███████║   ██║   ██║  ██║      ███████║██║ ╚████║██║██║     ██║     ███████╗   ██║
╚══════╝   ╚═╝   ╚═╝  ╚═╝      ╚══════╝╚═╝  ╚═══╝╚═╝╚═╝     ╚═╝     ╚══════╝   ╚═╝

```

# convert any file into a code snippet to store in VSCode

- ex if u have this file `plz.cpp`

```cpp
#include <iostream>
#include <vector>
#include <memory>

class MyClass {
public:
    MyClass(int data) : data_(data) {
        std::cout << "Constructing MyClass with data: " << data_ << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructing MyClass with data: " << data_ << std::endl;
    }

    void processData() {
        std::cout << "Processing data: " << data_ << std::endl;
        // Perform data processing...
    }

private:
    int data_;
};

int main() {
    std::cout << "Creating vector of MyClass objects" << std::endl;

    std::vector<std::unique_ptr<MyClass>> myObjects;

    // Add objects to the vector
    myObjects.emplace_back(std::make_unique<MyClass>(1));
    myObjects.emplace_back(std::make_unique<MyClass>(2));
    myObjects.emplace_back(std::make_unique<MyClass>(3));

    std::cout << "Processing objects" << std::endl;

    // Process each object in the vector
    for (const auto& obj : myObjects) {
        obj->processData();
    }

    std::cout << "End of program" << std::endl;

    return 0;
}
```

- you can use the binary produced from this code to convert it into a snippet

```bash
str2snip plz.cpp -
```

- output - paste this into any snippets file `Settings > Configure User Snippets > any`

- After pasting below - during development we can type `cppsmartmem` and it will auto generate the code below

```json
Creating Snippet for extremelyGoodMemoryMgmt

"Snippet Title Here": {
    "prefix":"cppsmartmem",
    "body": [
      "#include <iostream>",
      "#include <vector>",
      "#include <memory>",
      "class MyClass {",
      "public:",
      "\tMyClass(int data) : data_(data) {",
      "\t\tstd::cout << \"Constructing MyClass with data: \" << data_ << std::endl;",
      "\t}",
      "\t~MyClass() {",
      "\t\tstd::cout << \"Destructing MyClass with data: \" << data_ << std::endl;",
      "\t}",
      "\tvoid processData() {",
      "\t\tstd::cout << \"Processing data: \" << data_ << std::endl;",
      "\t\t// Perform data processing...",
      "\t}",
      "private:",
      "\tint data_;",
      "};",
      "int main() {",
      "\tstd::cout << \"Creating vector of MyClass objects\" << std::endl;",
      "\tstd::vector<std::unique_ptr<MyClass>> myObjects;",
      "\t// Add objects to the vector",
      "\tmyObjects.emplace_back(std::make_unique<MyClass>(1));",
      "\tmyObjects.emplace_back(std::make_unique<MyClass>(2));",
      "\tmyObjects.emplace_back(std::make_unique<MyClass>(3));",
      "\tstd::cout << \"Processing objects\" << std::endl;",
      "\t// Process each object in the vector",
      "\tfor (const auto& obj : myObjects) {",
      "\t\tobj->processData();",
      "\t}",
      "\tstd::cout << \"End of program\" << std::endl;",
      "\treturn 0;",
      "}"
    ],
    "description": "Benchmark tests using mock data for standard and Sonic JSON decoding."
},

```

- Symbolic Link for `main`

```bash
# Compile Code

g++ -std=c++20 -o main main.cpp utils.cpp transform.cpp -lpthread


# Creating a symbolic link for the binary

sudo ln -s /path/to/StringToSnippet/src/main /usr/local/bin/snippet

# Now you can run from anywhere

snippet filename

```
