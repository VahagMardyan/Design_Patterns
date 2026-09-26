#include <iostream>
#include <vector>

int get_max(int a, int b) {
    return a > b ? a : b;
}

void min_bribes(std::vector<int> &q) {
    int n = q.size();
    int bribes = 0;
    bool chaotic = false;
    for(int i=n-1;i>=0;i--) {
        if(q[i] - (i+1) > 2) {
            chaotic = true;
            break;
        }
        for(int j=get_max(0,q[i]-2); j<i; j++) {
            if(q[j] > q[i]) bribes++;
        }
    }
    if(chaotic) {
        std::cout<<"Too chaotic"<<'\n';
    } else {
        std::cout<<bribes<<'\n';
    }
}

int main() {
    int n;
    std::cout<<"n=";std::cin>>n;
    std::vector<int> queue(n);
    for(int i=0;i<n;i++) {
        std::cin>>queue[i];
    }
    min_bribes(queue);
    return 0;
}