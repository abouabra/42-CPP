#include "Serializer.hpp"

int main()
{
    Data data = (Data) {42, -42, "abouabra"};
    std::cout <<  "DATA:" << std::endl << "\tN1: " << data.n1 << std::endl << "\tN2: " << data.n2 << std::endl << "\tNAME: " << data.name  << std::endl;
    
    Data *result = Serializer::deserialize(Serializer::serialize(&data));
    std::cout <<  "RESULT:" << std::endl << "\tN1: " << result->n1 << std::endl << "\tN2: " << result->n2 << std::endl << "\tNAME: " << result->name  << std::endl;
    return 0;
}