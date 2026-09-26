#include <iostream>
#include <vector>

struct Vertex {
	float x, y, z;
	Vertex(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {}

	Vertex(const Vertex& v) : x(v.x), y(v.y), z(v.z) {
		std::cout << "Copied!" << std::endl;
	}
	~Vertex() {}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& v) {
	stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return stream;
}

//int main() {
//	std::vector<Vertex> vertices;
//	vertices.push_back(Vertex(1, 2, 3));
//	vertices.push_back(Vertex(4, 5, 6));
//	vertices.push_back(Vertex(7, 8, 9));
//	//for (Vertex& v : vertices) {
//	//	std::cout << v << std::endl;
//	//}
//	std::cin.get();
//	return 0;
//}

int main() {
	std::vector<Vertex> vertices;
	vertices.reserve(3);
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);
	for (Vertex& v : vertices) {
		std::cout << v << std::endl;
	}

	std::cin.get();
	return 0;
}

/* Vector optimization
	Այս ծրագիրը (first main) տպելու է 6 copied, ինչը նշանակում է, որ 6 անգամ copy է լինում, 
	իսկ սա դանդաղեցնում է ծրագրի աշխատանքը։ Ահա թե ինչպես է դա տեղի ունենում
		1. Stack -> main-ի stack-ում ստեղծվում է ժամանակավոր Vertex օբյեկտ
		2. Heap -> vector-ը վերցնում է այդ օբյեկտը և պատճենում իր հիշողության մեջ
		Ամեն push_back-ը ստեղծում է 1 Vertex => 3 copy
		Ամեն անգամ heap-ում պատճենվում է այդ տվյալները, դա ևս 3 copy
		Արդյունքում՝ 6 copy

	Դա լուծելու համար առաջարկվում է այս տարբերակը (second main)
		1. Allocator-ին հրահանգում ենք, թե vector-ը քանի տարրանոց է լինելու,
			և այն heap-ում միանգամից այդքան տեղ է զբաղեցնում։
		2․ push_back-ը ստանում է պատրաստի օբյեկտ և ամեն անգամ նոր հիշողություն է զբաղեցնում՝ պատճենելով հինը։
			Այս խնդրի լուծման համար օգտագործում են emplace_back-ը, որը ստանում է արգումենտներ և դրանցով
			 կառուցում օբյեկտը հենց vector-ի ներսի հիշողության մեջ։
			 Արդյունքում ավելորդ copy-ներից ազատվում ենք
*/