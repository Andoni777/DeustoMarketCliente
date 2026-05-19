/*
 * Inventario.h
 *
 * Created on: 11 may 2026
 * Author: andoni.g
 */

#ifndef DOMAIN_INVENTARIO_H_
#define DOMAIN_INVENTARIO_H_

class Inventario {
private:
    int id_super;
    int id_producto;
    int stock;

public:
    // Constructores
    Inventario();
    Inventario(int id_super, int id_producto, int stock);

    // Destructor
    virtual ~Inventario();

    // Getters y Setters
    int getIdSuper() const;
    void setIdSuper(int idSuper);

    int getIdProducto() const;
    void setIdProducto(int idProducto);

    int getStock() const;
    void setStock(int stock);
};

#endif /* DOMAIN_INVENTARIO_H_ */
