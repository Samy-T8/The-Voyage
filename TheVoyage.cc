#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class node{
    public:
        int id;
        string question;
        int x;
        int y;
        string hint;
        string leftans;
        string rightans;
        string upans;
        string downans;
        node* up;
        node* down;
        node* left;
        node* right;
        int leftaltitude;
        int rightaltitude;
        int upaltitude;
        int downaltitude;
        int correct_Answer;
        int damage;
        string explanation;
        bool isPirateIsland;
        node(int id,string question ,string hint, string leftans,string rightans,string upans,string downans,  string explanation , int correct_Answer , int la,int ra,int ua,int da , node * left , node * right , node * up , node * down,bool isPirateIsland = false ){
            this->id=id;
            this->left = left;
            this->right = right;
            this->up = up;
            this->down = down;
            this->leftans=leftans;
            this->rightans=rightans;
            this->upans=upans;
            this->hint=hint;
            this->downans=downans;
            this->question = question;
            this->correct_Answer = correct_Answer;
            this->leftaltitude=la;
            this->rightaltitude=ra;
            this->upaltitude=ua;
            this->downaltitude=da;
            this->explanation = explanation;
            this->damage = isPirateIsland ? (rand() % 21 + 10) : 0;
            this->isPirateIsland = isPirateIsland;
        }
};
struct QuestionData {
    string question;
    string answer;
    string explanation;
    int correctOption;
    bool isPirate;
};

class ship{
    public:
        int crew;
        int fuel;
        int hints;
        int weight;
        vector<pair<string, pair<int, int>>> treasures;
        ship(){
            crew=5;
            fuel=100;
            hints=3;
            weight=100;
            treasures={{"Diamond",{200,5}},{"Emerald",{300,10}}};
        }
        ship(int n,int f,int h,int w,vector<pair<string,pair<int,int>>> t){
            crew = n;
            fuel = f;
            hints = h;
            weight=w;
            treasures=t;
        }
        
};


class game{
    public:
        node* root;
        node* destination;
        int progress;

        game(){
            root = NULL;
            destination = NULL;
            progress = 0;
        }

        game(node * r, node * d){
            root = r;
            destination = d;
            progress = 0;
        }
};


class player{
    string password;
    public:
        string username;
        int registration_id;
        string title;
        node * LastNode;
        game current_game;
        ship current_ship;
        vector<node*> path_taken;
        player() {
            username = "";
            registration_id = -1;
            title = "Noobie";
            LastNode = NULL;
        }

        player(string password , string username, int registration_id){
            title = "Noobie";
            LastNode = NULL;
            this->password = password;
            this->username = username;
            this->registration_id = registration_id;
        }

        string getPassword(){
            return password;
        }
};

int formulaForRNAF(string username){
    int sum = 0;
    for(int i = 0; i < username.length(); i++){
        sum += (username[i] * pow(3 , i+1));
    }
    return sum;
}

void printCentered(const string& text, int width = 90) {
    int padding = (width - text.size()) / 2;
    cout << setw(padding + text.size()) << text << endl;
}

void showWelcomeScreen() {
    cout << setw(90) << "=========================================================================" << endl;
    cout << setw(90) << "|                     Welcome to THE VOYAGE                             |" << endl;
    cout << setw(90) << "|     <    Code or be Cursed - Only the Smart Survive!!     >           |" << endl;
    cout << setw(90) << "=========================================================================" << endl;

    // Ship ASCII Art
    sleep(2);

           
        cout << "                                            ______/|\\\\______" << endl;
        cout << "                                   ________/______|______\\\\__________________" << endl;
        cout << "                          ________/        O     O     O     O     O     O     \\\\______" << endl;
        cout << "                           \\\\             -|-   -|-   -|-   -|-   -|-   -|-             /" << endl;
        cout << "                            \\\\            | |   | |   | |   | |   | |   | |            /" << endl;
        cout << "                             \\\\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ /" << endl;
        cout << "                              \\\\____________________________________________________ /" << endl;
        cout << "                               \\\\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ /" << endl;
        cout << "                                 \\\\________________________________________________/" << endl;
        cout << "                              ~   ~    ~   ~   ~    ~   ~   ~   ~   ~   ~" << endl;
        cout << "                              Hold on tight, Crew Members! The storm is fierce!" << endl;
        cout << setw(90) << "=========================================================================" << endl;      
       

        

        return;

}

void showMainMenu() {    
    cout << endl;
    cout << endl;
    cout << setw(65) << "                 * * *  MAIN MENU  * * *" << endl;
    cout << setw(65) << "             --------------------------------" << endl;
    cout << setw(65) << "             |      1. Register            |" << endl;
    cout << setw(65) << "             |      2. Log In              |" << endl;
    cout << setw(65) << "             |      3. Exit                |" << endl;
    cout << setw(65) << "             --------------------------------" << endl;
    cout << setw(90) << "=========================================================================" << endl;
    cout << setw(50) << "Enter your choice: ";
    
}


void deleteAccount(player curr_player , unordered_map<int , player> &players_data) {
    int registered_no = curr_player.registration_id;
    players_data.erase(registered_no);
    printCentered("=======================================");
    printCentered("*** YOUR ACCOUNT IS DELETED SUCCESSFULLY ***");
    printCentered("=======================================");
    return;
}

void registration(unordered_map<int , player> &players_data){
    string username;
    string password;

    label:
        cout << endl;
        printCentered("*** USER REGISTRATION ***", 90);
        printCentered("===============================", 90);

        cout << setw(55) << ("Enter your username:");
        cout << " > ";
        cin >> username;

        int rnaf = formulaForRNAF(username);  // rnaf = Registered Number according to formula

        int left = 96;
        int right = 413280;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (players_data[mid].username == username) {
                printCentered("---------------------------------");
                printCentered("[!] Username already exists.");
                printCentered("    Please choose another username.");
                printCentered("---------------------------------");
                goto label;
            } else if (mid > rnaf) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << setw(55) << ("Enter your password:");
        cout << " > ";
        cin >> password;

        player p(password, username, rnaf);
        players_data[rnaf] = p;
       

        printCentered("***************************************");
        printCentered("Registration successful!");

        string regNoMsg = "Your registration number is: " + to_string(rnaf);
        printCentered(regNoMsg);
        printCentered("***************************************");
}

int login(unordered_map<int , player> players_data){
    string username = "";
    string password = "";
    int count = 0;

    printCentered("*** USER LOGIN ***", 90);
    printCentered("===============================", 90);

    cout << setw(55) << ("Enter your username:");
    cout << " > ";
    cin >> username;

    int rnaf = formulaForRNAF(username);
    if (players_data[rnaf].username == username) {
        label2:
            count++;
            if (count == 3) {
                printCentered("[!] Maximum login attempts exceeded.");
                return -1;
            }

            cout << setw(55) << ("Enter your password:");
            cout << " > ";
            cin >> password;

            if (players_data[rnaf].getPassword() == password) {
                printCentered("***************************************");
                printCentered("Login successful!");
               

            } else {
                printCentered("---------------------------------");
                printCentered("[!] Incorrect password. Try again.");
                printCentered("---------------------------------");
                goto label2;
            }
    } else {
        printCentered("---------------------------------");
        printCentered("[!] Username does not exist.");
        printCentered("---------------------------------");
        return -1;
    }
    return rnaf;
}


int calculateOptimalValue(const vector<pair<int, int>>& treasures, int W) {
    int n = treasures.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int val = treasures[i - 1].first;
        int wt = treasures[i - 1].second;
        for (int w = 1; w <= W; ++w) {
            if (wt <= w)
                dp[i][w] = max(dp[i - 1][w], val + dp[i - 1][w - wt]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}



pair<node*, node*> createMap() {
    // Create all nodes first
    node* n13 = new node(13,"Final Destination. Congratulations! You made it! Superb Captain.","", "left","right","up","down", 
                        "Congratulations! You made it!", 0, 0,0,0,0, nullptr, nullptr, nullptr, nullptr, false);
    
    node* n12 = new node(12," In C++, a function template is used to create functions that can operate on different data types. What will happen if a programmer tries to use a function template with an unsupported data type?", "Function templates are designed to handle multiple data types, but there are limits to this flexibility.",
        
        "The program will compile successfully, but the function will not work.","The program will work by converting the data type.",
        " The function temp will automatically specialize for that data type.",
        " The compiler will generate an error.",
        "If a programmer tries to use a function template with an unsupported data type (e.g., a type that doesn't support the required operations), the compiler will generate an error. C++ templates are type-safe, and they will not allow you to instantiate a template with types that don't meet the function's requirements.",
        3, 20,20,10,20,nullptr, nullptr, n13 , nullptr, true);
    node* n11 = new node(11,"A class uses new to allocate memory in the constructor but forgets to delete it in the destructor. What is the consequence?", "The object disappears, but its memory doesn't. Think: what happens to memory that's not explicitly returned?",
        
        "Stack overflow","Memory leak","Segmentation fault","Double free",
        "In C++, when you use new, the memory is allocated from the heap, not the stack. This memory stays allocated until you explicitly delete it. If you forget to delete, the memory isn't reclaimed—even after the object is destroyed.\n        1) When the destructor doesn't free the memory, the object goes out of scope, but the heap memory it points to stays around.\n        2) Over time, if this happens repeatedly (e.g., in loops or dynamic structures), your program can consume more and more memory, eventually slowing down or crashing.", 2, 20,10,20,0, nullptr, n12, nullptr, nullptr, false);

    node* n10 = new node(10,"class Base {\n\
        public:\n\
            virtual void show() { cout << \"Base\"; }\n\
    };\n\
    class Derived : public Base {\n\
        public:\n\
            void show() { cout << \"Derived\"; }\n\
    };\n\
    Base* b = new Derived();\n\
    b->show();",
             " The function is marked virtual. Ask yourself: what does the program actually see when calling through a base class pointer? ",
            
            " Base "," Undefined behavior "," Error "," Derived ",
            " In C++, when a function is marked virtual, it tells the compiler to use runtime polymorphism. That means the function call will be resolved based on the actual object type, not the pointer type.\n        1) Here, b is a pointer to Base, but it actually points to a Derived object.\n        2)	Because show() is virtual, the call to b->show() looks at the object type (Derived) and calls Derived::show().",
            4, 20,20,20,10,nullptr, n12, nullptr, nullptr, false);
    node* n9 = new node(9,"Rahul wants to ensure that a base class cannot be instantiated directly but can still be inherited. Which technique should he use?", "You want to create a template for future classes-one that requires specific behavior to be defined in the child. What kind of function does that?",
        "Use final keyword","Use a pure virtual function","Make the constructor private","Make the class static", 
        "This tells the compiler: This function must be overridden in derived classes. The base class is abstract and can't be used directly.\n        1) A class with at least one pure virtual function becomes an abstract class.\n        2)You cannot create objects of abstract classes, but you can inherit from them.\n        3)This is a way to define a blueprint or interface for other classes to follow.", 2, 20,10,20,20, nullptr,n13,n12, n10 , true);
    node* n8 = new node(8,
        "Eve wants to overload the + operator to add two Complex numbers, where the real and imaginary parts are stored as integers. Which of the following would be the correct operator overloading method for the + operator?",
        
        "The operator should work with two Complex objects and return the result as a new Complex number.",
        
        "Complex operator+() {\n\
        \t\treturn Complex(real + other.real, imag + other.imag);\n\
    }",
    
        "Complex operator+(const Complex& other) {\n\
        \t\treturn Complex(real + other.real, imag + other.imag);\n\
    }",
    
        "Complex operator+(Complex other) {\n\
        \t\treturn Complex(real + other.real, imag + other.imag);\n\
    }",

        "Complex operator+(Complex& other) {\n\
        \t\treturn Complex(real + other.real, imag + other.imag);\n\
    }",
    
        "When overloading operators, the correct approach is to pass objects as references to avoid unnecessary copies. The const keyword ensures that the passed object is not modified. Option 2 correctly overloads the + operator. Option 1 lacks a parameter and doesn't work. Option 3 does not use const, making it less efficient and potentially modifying the other object.",
    
        2, 20, 10, 20, 20, nullptr, n13, nullptr, nullptr, false
    );
    node* n7 = new node(7,
        "Kevin is working on a C++ class to manage network connections. He wants to ensure that only one instance of the ConnectionManager class exists throughout the entire program. Which design pattern should he implement to enforce this, and what is the correct way to do it in C++?",

        "This design pattern ensures a class has only one instance and provides a global point of access to it.",

        "Use a static object inside the class constructor",

        "Make the constructor public and create the object globally",

        "Use a private constructor and a static method to return a single instance",

        "Declare the class with all static members and no constructor",

        "The Singleton design pattern ensures that only one instance of a class is created and provides a global point of access to that instance. In C++, this is typically implemented by:\n 1. Making the constructor private (so no external objects can be created).\n 2. Creating a static method (usually called `getInstance()`) that returns a static instance of the class.",
        3, 20, 10, 20, 20, nullptr, n8, n13, nullptr, false
    );
    
    node* n6 = new node(6,
        "In a C++ program, you have a base class Shape with a virtual function area(), and derived classes Circle and Rectangle that implement their own versions of area(). "
        "When you create a pointer to Shape but point it to an object of Circle, which method will be called when area() is invoked on the pointer?",
    
        "Polymorphism allows derived class methods to override base class methods.",
    
        "This will cause runtime error",
    
        "The area() method of Shape",
    
        "The area() method of Rectangle",
    
        "The area() method of Circle",
    
        "This is an example of runtime polymorphism in C++. Since area() is a virtual function in the base class (Shape), it allows the derived class (Circle) to override it. "
        "When calling area() on a base class pointer that points to a Circle object, the Circle's area() method will be invoked.",
    
        4, 20, 20, 20, 10, nullptr, nullptr, nullptr, n11, true
    );
    
    node* n5 = new node(5,"Alice is writing a program to calculate the factorial of a number using recursion. "
        "Which of the following function definitions correctly implements the recursive calculation of factorial?",
    
        "Base case and recursive step are critical in recursion.",
    
        "int factorial(int n) {\n"
        "  \t\t \t\t\t\t \t\tif (n == 1) return 0;\n"
        "  \t\t \t\t\t\t \t\treturn n * factorial(n + 1);\n"
        "}",
    
        "int factorial(int n) {\n"
        "   \t\t\t\t\t\t \t\treturn n * factorial(n - 1);\n"
        "}",
    
        "int factorial(int n) {\n"
        "   \t\t\t\t \t\t\t\tif (n == 0) return 1;\n"
        "   \t\t\t\t \t\t\t\treturn n * factorial(n - 1);\n"
        "}",
    
        "int factorial(int n) {\n"
        "   \t\t\t\t \t\t\t\tif (n == 1) return 1;\n"
        "   \t\t\t\t \t\t\t\treturn factorial(n - 1);\n"
        "}",
    
        "This function implements recursion correctly. The base case (n == 0) returns 1, and the recursive step reduces n by 1, calling factorial(n - 1). "
        "Option 1 has an incorrect base case (n == 1 returning 0, which is wrong for factorials). "
        "Option 2 lacks a proper base case, which would lead to infinite recursion. "
        "Option 4 has an incomplete recursive step that doesn't multiply by n.",
        
        3, 20, 20, 10, 20, n6, nullptr,n7, nullptr, false
    );

    
    node* n4 = new node(4,
        "Mark wants to pass an array to a function that will print all its elements. "
        "Which of the following function prototypes is correct for passing an array of integers?",
    
        "The correct way to pass an array in C++ is via pointers.",
    
        "void printArray(int arr[5]);",
    
        "void printArray(int arr[]);",
    
        "void printArray(int *arr);",
    
        "All of the above",
    
        "In C++, arrays are passed to functions as pointers, meaning that all the options are valid. "
        "Option 1 uses a fixed size for the array (arr[5]), Option 2 uses a flexible size (arr[]), "
        "and Option 3 uses a pointer (int *arr). All approaches are valid for passing an array to a function, "
        "as the compiler interprets them as passing the address of the first element.",
    
        4, 20, 20, 20, 10, n6, n10, nullptr, n11, false
    );
    
    node *n3 = new node(3,
                        "In a program, Maria is writing a function that takes two integers as parameters and calculates their sum. "
                        "Which of the following function definitions correctly declares a function to calculate the sum of two integers?",
                    
                        "A valid function in C++ must specify the return type and include proper syntax for parameters.",
                    
                        "sum(int a, int b) { return a + b; }",
                    
                        "int sum(int a, int b): return a + b;",
                    
                        "int sum(int a, int b) { return a + b; }",
                    
                        "int sum() { return a + b; }",
                    
                        "In C++, functions must specify their return type. Option 3 correctly declares an int return type and properly defines the function with parameters int a and int b. "
                        "Option 1 lacks the return type. Option 2 uses incorrect syntax (colon instead of braces). "
                        "Option 4 has no parameters, so it cannot calculate the sum of two integers.",
                    
                        3, 20, 20, 10, 20, n5, n8, n7, nullptr, true
                    );
                    
    
    node* n2 = new node(2,"Tom is writing a C++ program that dynamically allocates memory for an array of integers using new. "
        "He creates an array of 10 integers. After using the array, which of the following code snippets should he use to free the allocated memory?",
    
        "Dynamic memory allocation requires freeing memory with delete[].",
    
        "delete arr;",

        "delete[] arr;",
    
        "free(arr);",

        "arr.delete[];",
    
        "In C++, when memory is dynamically allocated using new[], it must be deallocated using delete[] to free the memory properly. "
        "Option 1 uses delete instead of delete[], which is used for single objects, not arrays. "
        "Option 2 uses free(), which is from C and not compatible with new[]. ",
        2, 20, 10, 20, 20, nullptr, n9, n8, n10, false);
    
    node* n1 = new node(1,"Sarah is trying to write a program to store the ages of 5 friends. She creates an array ages[5], "
    "and she enters the ages 18, 20, 22, 24, and 26. What is the correct way to access the third age (22) in the array?", "Array indices in C++ start from 0.",
                       "ages(3)","ages{3}","ages[2]","ages[3]",  
                       "the second is ages[1], and the third is ages[2]. Option C is the correct answer. "
    "Option 1 uses parentheses, which are used for function calls, not array access. "
    "Option 4 accesses the fourth element (value 24), not the third.", 3, 20, 20, 10, 20, nullptr, nullptr, n5, n6, false);
    
    node* n0 = new node(0,
        "John is working on a small C++ project where he needs to display "
        "\"Welcome to C++ Programming!\" on the screen. Which of the following code snippets would achieve this?",
    
        "The most common way to display text in C++",
    
        "cout(\"Welcome to C++ Programming!\");",
    
        "cout << \"Welcome to C++ Programming!\" << endl;",
    
        "printf(\"Welcome to C++ Programming!\");",
    
        "print(\"Welcome to C++ Programming!\");",
    
        "In C++, the standard way to output text is through the cout stream, using the insertion operator (<<) "
        "to send the text to the console. Option B is correct. Option A is incorrect because cout does not take "
        "parameters with parentheses — it requires <<. Option C uses printf(), which is a C-style output function "
        "and works, but it's not preferred in modern C++. Option D uses print(), which is not a valid C++ function.",
    
        2, 20, 10, 20, 20, n1, n2, n3, n4, false // right
    );

    n1->right = n0;
    n2->left = n0;
    n3->down = n0;
    n4->up = n0;
    n5->right=n3;
    n5->down=n1;
    n6->left = n5;
    n6->right=n4;
    n6->up=n1;
    n7->left=n5;
    n7->down = n9;
    n8->up=n7;
    n8->left=n3;
    n8->down = n2;
    n9->left=n2;
    n9->up = n7;
    n10->left=n4;
    n10->down = n9;
    n10->up = n2;
    n11->up=n4;
    n11->left = n6;
    n12->left=n11;
    n12->right = n9;
    n12->down = n10;
    n0->x = 1; n0->y = 1;
    n1->x = 1; n1->y = 3;
    n2->x = 1; n2->y = 5;
    n3->x = 1; n3->y = 7;
    n4->x = 2; n4->y = 7;
    n5->x = 0; n5->y = 0;
    n6->x = 3; n6->y = 1;
    n7->x = 0; n7->y = 2;
    n8->x = 1; n8->y = 2;
    n9->x = 1; n9->y = 4;
    n10->x = 3; n10->y = 3;
    n11->x = 4; n11->y = 0;
    n12->x = 4; n12->y = 2;
    n13->x = 2; n13->y = 8;
    vector<vector<node*>> nodeGrid(5, vector<node*>(9, nullptr));
    nodeGrid[1][1] = n0;
    nodeGrid[1][3] = n1;
    nodeGrid[1][5] = n2;
    nodeGrid[1][7] = n3;
    nodeGrid[2][7] = n4;
    nodeGrid[0][0] = n5;
    nodeGrid[3][1] = n6;
    nodeGrid[0][2] = n7;
    nodeGrid[1][2] = n8;
    nodeGrid[1][4] = n9;
    nodeGrid[3][3] = n10;
    nodeGrid[4][0] = n11;
    nodeGrid[4][2] = n12;
    nodeGrid[2][8] = n13;
    return {n0, n13}; 
}




void askQuestion(node * island , player & currplayer){
    printCentered("Press Enter to Continue...");
    cin.ignore();
    cin.get();
   
    // Print Up movement option (if available)
    printCentered("**************************************");
    printCentered("                                      ");
    cout << ("    Ques) " + island->question + "    ") << endl;;
    printCentered("                                      ");
    printCentered("**************************************");
    cout << endl;

    // Print Up movement option (if available)
    if (island->left) {
        printCentered("    ---------------------------------" , 95);
        printCentered("     1)For West Island  (<) " + island->leftans , 95);
        printCentered("    ---------------------------------" , 95);
        cout << endl;
    }

    if(island->right){
        printCentered("    ---------------------------------" , 95);
        printCentered("     2)For East Island  (>) " + island->rightans , 95);
        printCentered("    ---------------------------------" , 95);
        cout << endl;
    }

    if (island->up) {
        printCentered("    ---------------------------------" , 95);
        printCentered("     3)For North Island  (^) " + island->upans , 95);
        printCentered("    ---------------------------------" , 95);
        cout << endl;
    }

    if (island->down) {
        printCentered("    ---------------------------------" , 95);
        printCentered("     4)For South Island  (v) " + island->downans , 95);
        printCentered("    ---------------------------------" , 95);
    }

    // Leave game option
    cout << endl;
    int hints = currplayer.current_ship.hints;
    cout << "                5) To Leave Game Here                                  6) HINTS(" << hints << ") " << endl;
    cout << endl;

    // Final message
    printCentered("So, What do you think, Captain?");
    printCentered("Our lives are in your hands!!");

    return;
}

void ShowHint(node * island , player & currplayer){
    sleep(1);
   

    printCentered("THE HINT FOR THIS ISLAND IS:"+island->hint);

    // Final message
    printCentered("So, What do you think, Captain?");
    printCentered("Our lives are in your hands!!");
    return;
}


void printGameStats(player currplayer){
    sleep(1);
    cout << endl;
    cout << endl;
    printCentered("Crew Members alive: "  ,80);
    string villager[] = {
        "      O    ",
        "     /|\\   ",
        "    / | \\  ",
        "     / \\   ",
        "    /   \\  ",
        "  _/_____\\_",
    };

    int rows = sizeof(villager) / sizeof(villager[0]);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < currplayer.current_ship.crew; j++) {
            cout << "       " << villager[i] << "   ";  
        }
        cout << endl;
    }
    cout << endl;
    sleep(2);
    printCentered("Fuel left: ", 80);
    const int tankHeight = 10;  // Total height of the tank
    int fuelLevel = (currplayer.current_ship.fuel * tankHeight) / 100;  // Calculate filled rows

    cout << endl;
    printCentered("  ________________  ", 80);
    printCentered(" |                | " , 80);

    for (int i = 0; i < tankHeight; i++) {
        if (i < tankHeight - fuelLevel) {
            printCentered(" |                | " , 80);  // Empty part
        } else {
            printCentered(" |~~~~~~~~~~~~~~~~| " , 80);
        }
    }
    printCentered(" |________________| ", 80);
    printCentered("FUEL: " + to_string(currplayer.current_ship.fuel) , 80 );
}
void showTreasures(vector<pair<string, pair<int, int>>>& treasures) {
    printCentered("Current treasures onboard:");
    for (int i = 0; i < treasures.size(); ++i) {
        cout <<"                             " << i+1 << ". " << treasures[i].first 
             << "                              | Value: " << treasures[i].second.first 
             << "                              | Weight: " << treasures[i].second.second << endl;
    }
}
                             
void manualTreasureDrop(player &currplayer, int allowedCapacity) {
    vector<pair<string, pair<int, int>>>& t = currplayer.current_ship.treasures;
    int totalWeight = 0;
    for (auto &tr : t) totalWeight += tr.second.second;

    if (totalWeight <= allowedCapacity) return;

    cout << endl;
    showTreasures(t);
    cout << "\n                               Damage at this node reduces your weight limit to " << allowedCapacity << ".\n";
    cout << "                                 Total treasure weight = " << totalWeight << endl;
    cout << "                                 You must discard at least " << (totalWeight - allowedCapacity) << " units.\n";

    unordered_set<int> droppedIndices;
    while (totalWeight > allowedCapacity) {
        int drop;
        cout << "\n                             Enter index of treasure to throw (1 to " << t.size() << "): ";
        cin >> drop;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "                             Invalid input. Please enter a number.\n";
            continue;
        }

        if (drop >= 1 && drop <= t.size() && droppedIndices.count(drop - 1) == 0) {
            int idx = drop - 1;
            totalWeight -= t[idx].second.second;
            droppedIndices.insert(idx);

            cout << " Dropped " << t[idx].first 
                 << " | Value: " << t[idx].second.first 
                 << " | Weight: " << t[idx].second.second << endl;
            cout << "                             Updated weight: " << totalWeight << "/" << allowedCapacity << endl;
        } else {
            printCentered("***************************************");
            cout << "                             Invalid index or already dropped.\n";
            printCentered("***************************************");
        }
    }

    // Compute actual value kept by player
    int droppedValue = 0, totalValue = 0, keptValue = 0;
    for (int i = 0; i < t.size(); ++i) {
        totalValue += t[i].second.first;
        if (droppedIndices.count(i)) droppedValue += t[i].second.first;
        else keptValue += t[i].second.first;
    }

    // Compute optimal value via knapsack
    int n = t.size();
    vector<int> values(n), weights(n);
    for (int i = 0; i < n; ++i) {
        values[i] = t[i].second.first;
        weights[i] = t[i].second.second;
    }

    vector<vector<int>> dp(n + 1, vector<int>(allowedCapacity + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= allowedCapacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    int optimalValue = dp[n][allowedCapacity];

    // Remove dropped treasures
    vector<pair<string, pair<int, int>>> updated;
    for (int i = 0; i < t.size(); ++i) {
        if (!droppedIndices.count(i)) {
            updated.push_back(t[i]);
        }
    }
    t = updated;

    // Final report
    printCentered("***************************************");
    cout << "\n                              You dropped treasure worth " << droppedValue 
         << " out of " << totalValue << endl;
    cout << "                              Your kept value: " << keptValue 
         << " | Optimal possible: " << optimalValue << endl;

    if (keptValue >= optimalValue) {
        printCentered("                              Incredible! You made the best possible choices!", 80);
    } else if (keptValue >= optimalValue * 0.75) {
        printCentered("                              Good choices, Captain! Nearly optimal!", 80);
    } else if (keptValue >= optimalValue * 0.5) {
        printCentered("                              Not bad... but there was a better combo!", 80);
    } else {
        printCentered("                              Big L, Captain. You lost too much valuable loot!", 80);
    }
    printCentered("***************************************");
}



void displayMap(node* current, const vector<vector<node*>>& grid) {
    sleep(2);
    cout << "\n  THE VOYAGE MAP \n\n";

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            node* n = grid[i][j];
            if (n == nullptr) {
                cout << "     ";
            } else if (n == current) {
                cout << "  STARTING ISLAND  ";
            } else if (n->question.find("Starting") != string::npos) {
                cout << "  S  ";
            } else if (n->question.find("Final") != string::npos) {
                cout << "  DESTINATION  ";
            } else if (n->isPirateIsland) {
                cout << "  PIRATE ISLAND  ";
            } else {
                cout << "  ISLAND ";
            }
        }
        cout << "\n";

        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] && j + 1 < grid[i].size() && grid[i][j + 1]) {
                node* from = grid[i][j];
                node* to = grid[i][j + 1];
                if ((from->right == to) || (to->left == from)) {
                    cout << "  ";
                } else {
                    cout << "     ";
                }
            } else {
                cout << "     ";
            }
        }
        cout << "\n";

        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] && i + 1 < grid.size() && grid[i + 1][j]) {
                node* from = grid[i][j];
                node* to = grid[i + 1][j];
                if ((from->down == to) || (to->up == from)) {
                    cout << "   ";
                } else {
                    cout << "     ";
                }
            } else {
                cout << "     ";
            }
        }
        cout << "\n";
    }

    cout << "\nLegend: S = Start, D = Destination, P = Pirate Island, \n";
    cout << endl;
    cout << endl;
    printCentered("Press Enter to Continue...");
    cin.ignore();
    cin.get();
}


void generateNodeGrid(node* root, vector<vector<node*>>& grid, int rows = 10, int cols = 10) {
    set<node*> visited;

    queue<tuple<node*, int, int>> q;
    q.push({root, rows / 2, cols / 2}); 

    while (!q.empty()) {
        node* current;
        int x, y;
        tie(current, x, y) = q.front();
        q.pop();

        if (!current || visited.count(current)) continue;
        visited.insert(current);
        current->x = x;
        current->y = y;

        // Bounds check and place in grid
        if (x >= 0 && x < rows && y >= 0 && y < cols)
            grid[x][y] = current;

        if (current->up)    q.push({current->up,    x - 1, y});
        if (current->down)  q.push({current->down,  x + 1, y});
        if (current->left)  q.push({current->left,  x, y - 1});
        if (current->right) q.push({current->right, x, y + 1});
    }
}

void evaluatePlayerPerformanceRanked(
    int finalFuel,
    int crewRemaining,
    int initialFuel,
    int initialTreasureWeight,
    vector<pair<string, pair<int, int>>> treasure,
    const vector<node*>& path_taken,
    const vector<pair<vector<int>, int>>& allPaths,
    player &currplayer
) {
    cout << "\n Evaluating your voyage...\n";
    //cout << "DEBUG: allPaths size = " << allPaths.size() << "\n";
    if (allPaths.empty()) {
        cout << "No valid paths found from start to destination.\n";
        return;
    }
    int bestFuelCost = allPaths[0].second;
    int worstFuelCost = allPaths.back().second;

    int sum = 0;
    for (const auto& edge : allPaths) {
        sum += edge.second;
    }
    double avgFuelCost = static_cast<double>(sum) / allPaths.size();
    int playerFuelUsed = initialFuel - finalFuel;

    int pirateVisited = 0;
    for (size_t i = 0; i < path_taken.size(); ++i) {
        if (path_taken[i] && path_taken[i]->isPirateIsland)
            pirateVisited++;
    }

    int finalTreasureWeight=0;
    for(auto t:treasure){
        finalTreasureWeight+=t.second.second;
    }
    int treasureLost = initialTreasureWeight - finalTreasureWeight;
    if (treasureLost < 0) treasureLost = 0;

    int left = 0, right = allPaths.size() - 1;
    int playerRank = allPaths.size();  

    while (left <= right) {
        int mid = (left + right) / 2;
        if (allPaths[mid].second >= playerFuelUsed) {
            playerRank = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    double percentile = (double)(playerRank + 1) / allPaths.size() * 100;

    // Display the report
    sleep(3);
    cout << "\n==========  CAPTAIN'S PERFORMANCE REPORT  ==========\n";
    cout << "Fuel Used by You           : " << playerFuelUsed << "\n";
    cout << "Your Remaining Fuel        : " << finalFuel << "\n";
    cout << "Crew Members Survived      : " << crewRemaining << "\n";
    cout << "Treasure Carried           : " << finalTreasureWeight << " / " << initialTreasureWeight << "\n";
    cout << "Treasure Lost              : " << treasureLost << "\n";
    cout << "Pirate Islands Visited     : " << pirateVisited << "\n";
    cout << "Steps Taken                : " << path_taken.size()-2 << "\n";
    cout << "--------------------------------------------------------\n";
    cout << "Best Fuel Cost             : " << bestFuelCost << "\n";
    cout << "Average Fuel Cost          : " << avgFuelCost << "\n";
    cout << "Worst Fuel Cost            : " << worstFuelCost << "\n";
    cout << "Your Path Rank             : " << playerRank + 1 << " / " << allPaths.size() << "\n";
    cout << "Efficiency Percentile      : " << 100.0 - percentile << "%\n";
    cout << "--------------------------------------------------------\n";

    // Achievements based on ranking and stats
    if (percentile <= 10.0 && crewRemaining >= 2 && treasureLost == 0) {
        cout << " ACHIEVEMENT UNLOCKED: LEGENDARY VOYAGER\n";
        currplayer.title = "LEGENDARY VOYAGER";
        
    } else if (percentile <= 30.0 && crewRemaining >= 1) {
        cout << " ACHIEVEMENT UNLOCKED: EFFICIENT EXPLORER\n";
        currplayer.title = "EFFICIENT EXPLORER";
    } else if (crewRemaining == 0) {
        cout << " All crew lost! But you made it. That's commitment.\n";
        currplayer.title = "WARRIOR";
    } else {
        cout << " You completed the journey! Try again to optimize further.\n";
        currplayer.title = "WARRIOR";
    }

    cout << "========================================================\n\n";


}
void dfsPathsWithRevisits(node* current, node* destination,
    vector<int>& path, int cost,
    vector<pair<vector<int>, int>>& allPaths,
    int depth , int maxDepth ) {

    if (!current || depth > maxDepth) return;

    path.push_back(current->id);  

    if (current == destination) {
        allPaths.push_back({path, cost});
        path.pop_back();
        return;
    }

    if (current->up)
        dfsPathsWithRevisits(current->up, destination, path, cost + current->upaltitude, allPaths, depth + 1, maxDepth);
    if (current->down)
        dfsPathsWithRevisits(current->down, destination, path, cost + current->downaltitude, allPaths, depth + 1, maxDepth);
    if (current->left)
        dfsPathsWithRevisits(current->left, destination, path, cost + current->leftaltitude, allPaths, depth + 1, maxDepth);
    if (current->right)
        dfsPathsWithRevisits(current->right, destination, path, cost + current->rightaltitude, allPaths, depth + 1, maxDepth);

    path.pop_back();  
}

vector<pair<vector<int>, int>> getAllPathsWithRevisits(node* root, node* destination, int maxDepth) {
    vector<pair<vector<int>, int>> allPaths;
    vector<int> path;
    dfsPathsWithRevisits(root, destination, path, 0, allPaths, 0, maxDepth);
    return allPaths;
}
void gamePlay(player &currplayer){
    node * move = currplayer.current_game.root;
    node* root=currplayer.current_game.root;
    node* destination = currplayer.current_game.destination;
    currplayer.path_taken.push_back(currplayer.LastNode);

    int input3;
    while(move != currplayer.current_game.destination){
        if(currplayer.current_ship.crew == 0){
            printCentered("NOOOO, All the Crew Members are killed....GAME OVER", 80);
            printCentered("***************************************", 80);
            return;
        }
        if(currplayer.current_ship.fuel == 0){
            printCentered("***************************************", 80);
            printCentered("NOOOO, The ship is out of fuel....GAME OVER",80);
            printCentered("***************************************", 80);
            return;
        }
        if(currplayer.current_ship.fuel == 0 && currplayer.current_ship.crew == 0){
            printCentered("***************************************", 80);
            printCentered("NOOOO, The ship is out of fuel and all the Crew Members are dead...GAME OVER");
            printCentered("***************************************", 80);
            return;
        }
        if(currplayer.current_ship.treasures.size()==0){
            printCentered("***************************************", 80);
            printCentered("NOOOO, The ship has no treasure to transport...GAME OVER");
            printCentered("***************************************", 80);
            return;
        }
        printGameStats(currplayer);
        sleep(2);
            if(!currplayer.LastNode->isPirateIsland){
                askQuestion(currplayer.LastNode , currplayer);
        label4:
            while (true) {
                cin >> input3;
                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter an integer: " << endl;
                } 
                else {
                    break;
                }
            }            
            if(input3 == 6){
                if(currplayer.current_ship.hints == 0){
                    printCentered("***************************************", 80);
                    printCentered("No hints left, Use your brain....You will find the way captain!!", 80);
                    printCentered("Make a move...Show us some skills!!", 80);
                    goto label4;
                }
                currplayer.current_ship.hints --;
                ShowHint(currplayer.LastNode , currplayer);
                goto label4;
            }
            if(input3 == 5){
                return;
            }
                if (input3 == currplayer.LastNode->correct_Answer) {
                    printCentered("***************************************", 80);
                    printCentered("Yay! Captain you are correct....Thank you so much!!!", 80);
                    printCentered("***************************************", 80);
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    printCentered("Explaination : " + currplayer.LastNode->explanation);
                    sleep(1);
                    
                    if (input3 == 1 && currplayer.LastNode->left != nullptr) {
                        currplayer.current_ship.fuel -= currplayer.LastNode->leftaltitude;
                        currplayer.LastNode = currplayer.LastNode->left;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if (input3 == 2 && currplayer.LastNode->right != nullptr) {
                        currplayer.current_ship.fuel -=  currplayer.LastNode->rightaltitude;
                        currplayer.LastNode = currplayer.LastNode->right;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if (input3 == 3 && currplayer.LastNode->up != nullptr) {
                        currplayer.current_ship.fuel -= currplayer.LastNode->upaltitude;
                        currplayer.LastNode = currplayer.LastNode->up;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if (input3 == 4 && currplayer.LastNode->down != nullptr) {
                        currplayer.current_ship.fuel -= currplayer.LastNode->downaltitude;
                        currplayer.LastNode = currplayer.LastNode->down;
                        currplayer.path_taken.push_back(currplayer.LastNode);
                    }
                    move = currplayer.LastNode;
                }
                else{
                    printCentered("***************************************", 80);
                    printCentered("Oh noo captain!! you are wrong!!", 80);
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "Explaination : " << currplayer.LastNode->explanation << endl;
                    printCentered("***************************************", 80);
                    sleep(1);
                    currplayer.current_ship.crew --;
                    if(input3 == 1 && currplayer.LastNode->left!=NULL){
                        currplayer.current_ship.fuel -= currplayer.LastNode->leftaltitude;
                        currplayer.LastNode = currplayer.LastNode->left;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if(input3 == 2 && currplayer.LastNode->right!=NULL){
                        currplayer.current_ship.fuel -= currplayer.LastNode->rightaltitude;
                        currplayer.LastNode = currplayer.LastNode->right;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if(input3 == 3 && currplayer.LastNode->up!=NULL){
                        currplayer.current_ship.fuel -= currplayer.LastNode->upaltitude;
                        currplayer.LastNode = currplayer.LastNode->up;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if(input3 ==4 && currplayer.LastNode->down!=NULL){
                        currplayer.current_ship.fuel -= currplayer.LastNode->downaltitude;
                        currplayer.LastNode = currplayer.LastNode->down;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    move = currplayer.LastNode;
                }
            }

            else{
                cout << endl;
                sleep(2);
                printCentered("**********************************************************", 90);
                cout << endl;
                printCentered("OHH NOO...Pirate Attack! Answer this to survive:" , 90);
                printCentered("Either you can defeat the pirate and include him in your team" , 90);
                printCentered("Or The pirate is going to steal the tresure from you" , 90);
                printCentered("HAHAHA this is going to be crazy...Read the question carefully" , 90);
                cout << endl;
                printCentered("***********************************************************", 90);

                askQuestion(currplayer.LastNode , currplayer);
        label5:
            while (true) {
                cin >> input3;
                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter an integer: " << endl;
                } 
                else {
                    break;
                }
            }            
            if(input3 == 6){

                if(currplayer.current_ship.hints == 0){
                    printCentered("***************************************", 90);
                    printCentered("No hints left, Use your brain....You will find the way captain!!", 90);
                    printCentered("Make a move...Show us some skills!!", 90);
                    goto label5;
                }
                currplayer.current_ship.hints --;
                ShowHint(currplayer.LastNode , currplayer);
                goto label5;
            }
            if(input3 == 5){
                return;
            }
                if (input3 == move->correct_Answer) {
                    currplayer.current_ship.crew++;
                     if (input3 == 1 && currplayer.LastNode->left != nullptr) {
                        currplayer.current_ship.fuel -= currplayer.LastNode->leftaltitude;
                        currplayer.LastNode = currplayer.LastNode->left;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if (input3 == 2 && currplayer.LastNode->right != nullptr) {
                        currplayer.current_ship.fuel -=  currplayer.LastNode->rightaltitude;
                        currplayer.LastNode = currplayer.LastNode->right;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if (input3 == 3 && currplayer.LastNode->up != nullptr) {
                        currplayer.current_ship.fuel -= currplayer.LastNode->upaltitude;
                        currplayer.LastNode = currplayer.LastNode->up;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if (input3 == 4 && currplayer.LastNode->down != nullptr) {
                        currplayer.current_ship.fuel -= currplayer.LastNode->downaltitude;
                        currplayer.LastNode = currplayer.LastNode->down;
                        currplayer.path_taken.push_back(currplayer.LastNode);
                    }
                    
                    printCentered("CONGRATS! You defeated the pirate and now he is your member");
                    printCentered("***************************************");
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "Explaination : " << move->explanation << endl;
                    printCentered("***************************************");
                    sleep(1);
                    move = currplayer.LastNode;
                } 
                else {
                    printCentered("***************************************");
                    printCentered("Oh noo captain!! you are wrong!!", 90);
                    cout << endl;cout << endl;
                    cout << endl;
                    cout << "Explaination : " << move->explanation << endl;
                    printCentered("***************************************", 90);
                    sleep(1);
                    cout << endl;
                    printCentered("Press Enter if you are ready to check your treasure...");
                    cin.ignore();
                    cin.get();
                    int newCapacity = currplayer.current_ship.weight - move->damage;
                    manualTreasureDrop(currplayer, newCapacity);
                    currplayer.current_ship.weight = newCapacity;
                    cout << endl;
                    printCentered("  Pirates stole your treasure!");
                    manualTreasureDrop(currplayer, currplayer.current_ship.weight);
                    if (input3 == 1 && currplayer.LastNode->left != nullptr) {
                        currplayer.current_ship.fuel -= currplayer.LastNode->leftaltitude;
                        currplayer.LastNode = currplayer.LastNode->left;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if (input3 == 2 && currplayer.LastNode->right != nullptr) {
                        currplayer.current_ship.fuel -=  currplayer.LastNode->rightaltitude;
                        currplayer.LastNode = currplayer.LastNode->right;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if (input3 == 3 && currplayer.LastNode->up != nullptr) {
                        currplayer.current_ship.fuel -= currplayer.LastNode->upaltitude;
                        currplayer.LastNode = currplayer.LastNode->up;
                        currplayer.path_taken.push_back(currplayer.LastNode);

                    }
                    else if (input3 == 4 && currplayer.LastNode->down != nullptr) {
                        currplayer.current_ship.fuel -= currplayer.LastNode->downaltitude;
                        currplayer.LastNode = currplayer.LastNode->down;
                        currplayer.path_taken.push_back(currplayer.LastNode);
                    }
                    move = currplayer.LastNode;
                }
        }

    }
    

    if (move == currplayer.current_game.destination) {
        printCentered("*********************************************************");
        cout<<endl;
        cout << endl;
        cout << "\n You've reached the destination island!\n";
        cout << endl;
        cout << endl;
        printCentered("*********************************************************");
        auto allPaths = getAllPathsWithRevisits(root, destination, 5); 
        sort(allPaths.begin(), allPaths.end(), [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
            return a.second < b.second; 
        });
        // Step 2: Evaluate performance
        evaluatePlayerPerformanceRanked(
            currplayer.current_ship.fuel,
            currplayer.current_ship.crew,
            100, // initial fuel
            100, // initial treasure weight
            currplayer.current_ship.treasures,
            currplayer.path_taken,
            allPaths,
            currplayer
        );
        printCentered("Press Enter to Continue...");
        cin.ignore();
        cin.get();
        return;
    }

}



void StartNewGame(player &currplayer){
    sleep(2);
    cout << endl;
    cout << endl;
    printCentered("***************************************", 90);
    printCentered("**** Welcome aboard, brave soul! ***", 90);
    printCentered("**** You are the chosen one on a quest for the legendary treasure of Captain CodeBeard... ***", 90);
    printCentered("**** But beware! The map to the treasure is scattered across 13 ancient C++ riddles. ***", 90);
    printCentered("**** Each correct answer brings you one knot closer to glory. Each wrong one? Closer to Davy Jones' Locker... ***", 90);
    printCentered("**** Sharpen your mind, tighten your code... and sail forth! ***", 90);
    printCentered("**** Let the Pirate's Quiz begin! ***", 90);
    
    printCentered("***************************************", 90);
    cout << endl;
    sleep(2);

    cout << "               _~                                              ____________" << endl;
    cout << "            _~ )_)_~                                          /            \\" << endl;
    cout << "            )_))_))_)                                        |              |" << endl;
    cout << "            _!__!__!_                                        | TREASURE     |" << endl;
    cout << "            \\______t/                                        |              |" << endl;
    cout << "          ~~~~~~~~~~~~~                                      |______________|" << endl;
    cout << "    ~~~  Sailing the Seas of Syntax  ~~~                  The Treasure of CodeBeard"<<endl;
    cout << endl;
    
    
    printCentered("Press Enter to Continue...");
    cin.ignore();
    cin.get();

    int difficulty;
    cout << setw(90) << "=========================================================================" << endl;
    cout << setw(60) << "                 * * * Choose Difficulty Level * * *" << endl;
    cout << setw(65) << "             --------------------------------" << endl;
    cout << setw(65) << "             |      1. Easy                 |" << endl;
    cout << setw(65) << "             |      2. Medium               |" << endl;
    cout << setw(65) << "             |      3. Hard                 |" << endl;
    cout << setw(65) << "             --------------------------------" << endl;
    cout << setw(90) << "=========================================================================" << endl;
    cout << setw(60) << "Enter your choice: ";
    while (!(cin >> difficulty) || difficulty < 1 || difficulty > 3) {
        cout << "Invalid input. Please enter 1 (Easy), 2 (Medium), or 3 (Hard): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl;
    cout << endl;

    ship New_Ship;
    switch (difficulty) {
        case 1: // Easy
            New_Ship = ship(6, 100, 5, 100, {{"EMERALD",{300, 50}}, {"DIAMOND",{200, 20}},{"RUBY",{150,30}}});
            cout<<"                               YOU HAVE CHOOSEN EASY DIFFICULTY"<<endl;
            cout<<"                               YOU HAVE 6 CREW MEMBERS IN YOUR JOURNEY"<<endl;
            cout<<"                               YOU HAVE BEEN GIVEN 100 LITRES OF FUEL"<<endl;
            cout<<"                               YOU HAVE 5 HINTS TO SAVE YOUR SHIP FROM SINKING"<<endl;
            cout<<"                               YOUR SHIP HAS TOTAL 100 CAPACITY OF LUGGAGE"<<endl;
            cout<<"                               YOUR SHIP HAS VALUABLE TREASURE- EMERALD, DIAMOND AND RUBY. CARRY THEM SAFELY"<<endl;
            break;
        case 2: // Medium
            New_Ship = ship(5, 100, 3, 100, {{"EMERALD",{300, 50}}, {"DIAMOND",{200, 20}},{"RUBY",{150,30}}});
            cout<<"                               YOU HAVE CHOOSEN MEDIUM DIFFICULTY"<<endl;
            cout<<"                               YOU HAVE 5 CREW MEMBERS IN YOUR JOURNEY"<<endl;
            cout<<"                               YOU HAVE BEEN GIVEN 100 LITRES OF FUEL"<<endl;
            cout<<"                               YOU HAVE 3 HINTS TO SAVE YOUR SHIP FROM SINKING"<<endl;
            cout<<"                               YOUR SHIP HAS TOTAL 100 CAPACITY OF LUGGAGE"<<endl;
            cout<<"                               YOUR SHIP HAS VALUABLE TREASURE- EMERALD, DIAMOND AND RUBY. CARRY THEM SAFELY"<<endl;
            break;
        case 3: // Hard
            New_Ship = ship(3, 100, 1, 100, {{"EMERALD",{300, 50}}, {"DIAMOND",{200, 20}},{"RUBY",{150,30}}});
            cout<<"                               YOU HAVE CHOOSEN HARD DIFFICULTY"<<endl;
            cout<<"                               YOU HAVE 3 CREW MEMBERS IN YOUR JOURNEY"<<endl;
            cout<<"                               YOU HAVE BEEN GIVEN 100 LITRES OF FUEL"<<endl;
            cout<<"                               YOU HAVE 1 HINTS TO SAVE YOUR SHIP FROM SINKING"<<endl;
            cout<<"                               YOUR SHIP HAS TOTAL 100 CAPACITY OF LUGGAGE"<<endl;
            cout<<"                               YOUR SHIP HAS VALUABLE TREASURE- EMERALD, DIAMOND AND RUBY. CARRY THEM SAFELY"<<endl;
            break;
    }
    printCentered("Press Enter to Continue...");
    cin.ignore();
    cin.get();

    pair<node*, node*> head = createMap();
    game New_Game(head.first, head.second);
    node* root=head.first;
    node* destination=head.second;
    currplayer.path_taken.clear();
    currplayer.path_taken.push_back(currplayer.LastNode);
    vector<vector<node*>> nodeGrid(10, vector<node*>(10, nullptr));
    auto allPaths = getAllPathsWithRevisits(root, destination, 5); 
    sort(allPaths.begin(), allPaths.end(), [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
        return a.second < b.second; 
    });

    
    generateNodeGrid(root, nodeGrid);
    currplayer.current_game = New_Game;
    currplayer.current_ship = New_Ship;
    currplayer.LastNode = head.first;
    displayMap(currplayer.LastNode, nodeGrid);
    gamePlay(currplayer);

    printCentered("***************************************");
    printCentered("**** HOPE YOU ENJOYED THE GAME ***");
    printCentered("***************************************");
}
void startend(node* root,node* dest){
    node* source=root;
    node* destination=dest;
}

void afterLogin(int registered_no , unordered_map<int , player> &players_data){
    player curr_player = players_data[registered_no];
    printCentered("Welcome, " + curr_player.username);
    printCentered("***************************************");
    int input2 = -1;
    while(input2 != 5){
        cout << setw(90) << "=========================================================================" << endl;
        cout << setw(60) << "                 * * *  THE VOYAGE  * * *" << endl;
        cout << setw(65) << "             --------------------------------" << endl;
        cout << setw(65) << "             |      1. New Game             |" << endl;
        cout << setw(65) << "             |      2. Continue             |" << endl;
        cout << setw(65) << "             |      3. Delete Account       |" << endl;
        cout << setw(65) << "             |      4. Print my Title       |" << endl;
        cout << setw(65) << "             |      5. Exit                 |" << endl;
        cout << setw(65) << "             --------------------------------" << endl;
        cout << setw(90) << "=========================================================================" << endl;
        cout << setw(60) << "Enter your choice: ";

        while (true) {
            cin >> input2;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Invalid input. Please enter an integer: " << endl;
            } 
            else {
                break;
            }
        }
            if(input2 == 1){
            StartNewGame(curr_player);
            continue;
            }
            else if(input2 == 2){
                if(curr_player.current_ship.fuel == 100){
                    printCentered("**** NO GAME SAVED ***");
                    printCentered("**** PLEASE START A NEW GAME ***");
                    continue;
                }
                if(curr_player.title != "Noobie"){
                    StartNewGame(curr_player);
                    continue;
                }
                gamePlay(curr_player);
            }
            else if(input2 == 3){
                deleteAccount(curr_player , players_data);
            }
            else if(input2 == 4){
                cout << endl;
                cout << setw(65) << "Your Title is : " << curr_player.title;
            }
    }
}
int main(){
    showWelcomeScreen();    
    unordered_map<int , player> players_data;
    int input1;
    label3:
        sleep(2);
        showMainMenu();
        while (true) {
            cin >> input1;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter an integer: ";
            } 
            else {
                break;
            }
        }
        while(input1 != 4){
            if(input1 == 1){
                registration(players_data);
                goto label3;
            }
            else if(input1 == 2){
                int registered_no = login(players_data);
                if(registered_no != -1){
                    afterLogin(registered_no , players_data);
                }
                goto label3;
            }
            else if(input1 == 3){
                input1 = 4;
            }
        }

        cout << setw(90) << "=========================================================================" << endl;
        cout << setw(90) << "|             THANK YOU FOR PLAYING THIS GAME CAPTAIN                    |" << endl;
        cout << setw(90) << "=========================================================================" << endl;
    return 0;
}
// 1 adi adi 2 adi adi 1 