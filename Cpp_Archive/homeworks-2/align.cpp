#include <iostream>
#include <vector>
using namespace std;

// vector<int> get_align(vector<int> input) {
//     int n = input.size();
//     vector<int> offsets(n);
//     int offset = 0;
    
//     for(int i=0;i<n;i++) {
//         int s = input[i];
//         if(s == 0) {
//             cout<<"Error: alignment cannot be 0"<<endl;
//             exit(1);
//         }
//         while(offset % s != 0) {
//             offset++;
//         }
//         offsets[i] = offset;
//         offset += s;
//     }

//     int max_align = 0;
//     for(int s : input) {
//         max_align = max(max_align, s);
//     }
//     while(offset % max_align != 0) {
//         offset++;
//     }
//     cout<<"Total size: "<<offset<<endl;

//     return offsets;
// }

int align(int size, int alignment) {
    int mod = size % alignment;
    if(mod == 0) {
        return size;
    }
    return size + (alignment - mod);
}

void get_align_info(vector<int>members) {
    int total_size = 0;
    cout<<"Result:"<<endl;
    for(int i=0;i<members.size(); i++) {
        int size = members[i];
        int aligned = align(total_size, size);
        int padding = aligned - total_size;
        cout << "Field " << i << ": size = " << size << ", address = " << aligned << ", padding before = " << padding << endl;
        total_size = aligned + size;
    }
    cout<<"Total size: "<<total_size<<" bytes"<<endl;
}

struct C {
    char x; // 1 byte
    int32_t a; // 4 bytes
    char y; // 1 byte
    int64_t b; // 8 bytes
    char z; // 1 byte
    int16_t c; // 2 bytes
};

template<class T>
void input_vector(vector<T>& v) {
    int n = 0;
    cout<<"Enter vector's size: ";cin>>n;
    v.resize(n);
    cout<<"Input vector: "<<endl;
    for(int i=0;i<v.size();i++) {
        cin>>v[i];
    }
}

template<class T>
void print_vector(const vector<T>& v) {
    cout<<"Vector: "<<endl;
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" "<<endl;
    }
}

int main() {
    vector<int> arr;
    input_vector(arr);
    get_align_info(arr);
    cout<<"C size: "<<sizeof(C)<<endl;
    return 0;
}

