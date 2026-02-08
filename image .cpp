#include <iostream>
using namespace std;

string img;
int loaded = 0;

int main() {
    int choice;

    while(true) {
        cout << "\nIMAGE PROCESSING TOOL\n";
        cout << "1. Load Image\n";
        cout << "2. Show Image\n";
        cout << "3. Apply Filter\n";
        cout << "4. Adjust Brightness / Color\n";
        cout << "5. Crop or Resize Image\n";
        cout << "6. Save Image\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter image name: ";
            cin >> img;
            loaded = 1;
            cout << "Image loaded.\n";
        }

        else if(choice == 2) {
            if(loaded == 1)
                cout << "Image displayed: " << img << endl;
            else
                cout << "No image loaded.\n";
        }

        else if(choice == 3) {
            if(loaded == 0) {
                cout << "Load image first.\n";
            } else {
                int f;
                cout << "1. Grayscale\n2. Blur\n3. Sharpen\nChoose filter: ";
                cin >> f;
                cout << "Filter applied.\n";
            }
        }

        else if(choice == 4) {
            if(loaded == 0)
                cout << "Load image first.\n";
            else
                cout << "Brightness and color adjusted.\n";
        }

        else if(choice == 5) {
            if(loaded == 0)
                cout << "Load image first.\n";
            else
                cout << "Image cropped and resized.\n";
        }

        else if(choice == 6) {
            if(loaded == 0)
                cout << "Load image first.\n";
            else
                cout << "Image saved successfully.\n";
        }

        else if(choice == 7) {
            cout << "Program ended.\n";
            break;
        }

        else {
            cout << "Wrong choice.\n";
        }
    }

    return 0;
}
