#include <stdio.h>
#include <vector>
class Ciudad {
  public:
    size_t poblacion = 0;
    size_t hospitales = 0;
    std::vector<size_t> adyacentes;
    Ciudad();
    Ciudad(size_t);
    Ciudad(size_t, std::vector<size_t>);
};