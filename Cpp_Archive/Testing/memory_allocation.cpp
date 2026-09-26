#include <iostream>
#include <memory>
#include <cstdint> // for uint32_t
#include <cstdlib> // for malloc and free

struct AllocationMetrics {
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;
    
    uint32_t CurrentUsage() {
        return TotalAllocated - TotalFreed;
    }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size) {
    s_AllocationMetrics.TotalAllocated += (uint32_t)size;
    return malloc(size);
}

void operator delete(void* memory, size_t size) noexcept {
    s_AllocationMetrics.TotalFreed += (uint32_t)size;
    free(memory);
}

void operator delete(void* memory) noexcept {
    free(memory);
}

static void PrintMemoryUsage() {
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

struct Object {
    double x, y, z;
};

int main() {
    PrintMemoryUsage(); // 0 bytes
    std::string str = "flropgkoirjkgiofejrwkfiuer9diewjfreiwhjforhd"; // 44 + 1 bytes
    PrintMemoryUsage();

    std::string small_str = "name";
    PrintMemoryUsage(); // 45 bytes. No changes because of SSO (will store into stack memory)
    
    {
        std::unique_ptr<Object> obj = std::make_unique<Object>(); // 3*4=12 bytes
        PrintMemoryUsage(); // 45 + 12 bytes
    } // smart pointer will delete the 'obj' pointer
    
    PrintMemoryUsage(); // 45 + 12 - 12 //bytes
    
    return 0;
}