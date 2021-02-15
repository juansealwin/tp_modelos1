#include <stdio.h>
#include <vector>
#include <map>

class Ciudad {
  public:
    size_t poblacion = 0;
    size_t hospitales = 0;
    size_t ranking_max_poblada = 0;
    std::vector<size_t> adyacentes;
    Ciudad();
    Ciudad(size_t);
    Ciudad(size_t, std::vector<size_t>);
    bool hay_hospital_disponible(std::map<size_t, Ciudad>&);
    // void ordenar_ciudades_por_poblacion(std::map<size_t, Ciudad>&);
    // void cambio_ciudades(Ciudad&, Ciudad&);
    void cambio_ciudades(Ciudad&);
    Ciudad& operator=(const Ciudad&);
};