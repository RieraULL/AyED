# Un ejemplo de una clase compleja

Ref. [code1a](vector/vector1/vector.hpp)
Ref. [code1b](vector/vector1/vector.cpp)
Ref. [code1c](vector/vector1/main.cpp)

Ref. [code2a](vector/vector2/vector.hpp)
Ref. [code2b](vector/vector2/vector.cpp)
Ref. [code2c](vector/vector2/main.cpp)

A continuación veremos una clase que representa un vector cuyos elementos son de tipo `double`. Aunque ya sabemos crear vectores genéricos mediante plantillas, queremos centrarnos en esta ocasión en las comparaciones y operaciones de números reales. En esta ocasión el código se presenta en tres ficheros. Un primer fichero `vector.hpp` en el que se incluye únicamente la declaración de la clase `vector`; un segundo fichero `vector.cpp` en el que se incluye la implementación de los métodos de la clase `vector`; y un último fichero `main.cpp` en el que se incluye el programa principal de nuestro sencillo programa. 

Estos tres ficheros deben compilarse con la llamada:
~~~
g++ -g main.cpp vector.cpp -o vector
~~~

El siguiente fragmento de código recoge la declaración de la clase, así como de dos operadores de entrada y salida.

~~~cpp
namespace AyED
{
  class vector
  {

  public:
    vector(void);
    vector(size_t sz);
    vector(const vector &v);
    ~vector(void);

    void resize(size_t sz);

    size_t size(void) const;
    double &at(size_t i);
    double at(size_t i) const;

    std::ostream &write(std::ostream &os) const;
    std::istream &read(std::istream &is);

    double &operator[](size_t i);
    double operator[](size_t i) const;

  private:
    void build(size_t sz);
    void destroy(void);

  private:
    double *base_;
    size_t sz_;
  };
}

std::ostream &operator<<(std::ostream &os, const AyED::vector &v);
std::istream &operator>>(std::istream &is, AyED::vector &v);
~~~

Como se puede observar esta clase define un tipo de dato que representa un vector. Tal y como ya habíamos avanzado en nuestra introducción sobre [punteros](punteros.md) un vector es en realidad una región de memoria de un tamaño determinado, que se ha reservado previamente, y accesible mediante un puntero. Por ello, la clase vector de nuestro ejemplo va a estar caracterizado por dos atributos: un puntero a la base del vector `base_`, y el tamaño del vector `sz_`. Aunque no es extrictamente necesario conocer el tamaño del vector, resulta conveniente con el fin de evitar desbordamientos en el acceso.

Vamos a crear tres constructores:

- Un constructor por defecto, que crea un vector de tamaño nulo. Para poder utilizar este vector podremos hacer uso del método `resize`, que permite cambiar el tamaño de nuestro vector.
- Un constructor al que se le pasa como parámetro el tamaño del vector.
- Y un constructor de copia. 

En este caso es de gran importancia llevar a cabo un constructor de copia, ya que, como habíamos adelantado en secciones anteriores, el constructor de copia que crea el compilador por defecto, copia en el objeto receptor los atributos del objeto original. Esto supone que si llevamos a cabo una llamada de este tipo:

~~~cpp
	vector a(5);
	vector b(a);
~~~

el vector `a` puede que tenga en sus atributos los valores `(0xA1B34, 5)`; así que al crear el vector `b` lo inicializaremos con el mismo contenido `(0xA1B34, 5)`. El gran inconveniente es que ambos vectores comparten la misma dirección base, por lo que si introducimos un elemento en el vector `a`:

~~~cpp 
	a[5] = 8;
~~~

habrá también un `8` almacenado en la posición 5 de `b`.

Por esta razón el constructor de copia que diseñemos debe reservar una región de memoria para `b` independiente de la región utilizada por el vector `a`.

Dentro de la familia de métodos podemos encontrar:

- un método `resize` para cambiar el tamaño del vector,
- un método `size` que devuelve el tamaño del vector,
- dos métodos `at` de acceso, uno de ellos para el caso de un objeto constante,
- dos métodos de entrada/salida,
- dos sobrecargas del operador `[]`,
- y dos métodos privados que gestionan la reserva y liberación de memoria.

Se muestra a continuación la implementación de dos constructores y el destructor.

~~~cpp
vector::vector(void):
base_(NULL),
sz_(0)
{}

vector::vector(size_t sz):
base_(NULL),
sz_(sz)
{
    build(sz_);
}

vector::~vector(void)
{
    destroy();
}

void vector::build(size_t sz)
{
    base_ = new double [sz];
}

void vector::destroy(void)
{
    if (base_ != NULL){

        delete [] base_;
        base_ = NULL;
    }
}
~~~

El segundo de los constructores llama al procedimiento privado `build` para reservar la memoria que requiere. Por otro lado, el destructor invoca al método privado `destroy`. Este último método libera la memoria apunta por `base_` en caso de que tuviera memoria asignada.

De igual manera, el método `resize` hace uso de estos dos métodos privados.

~~~cpp
void vector::resize(size_t sz)
{
    destroy();
    sz_ = sz;
    build(sz_);
}
~~~

Nótese que esta versión del método `resize` no preserva los datos que estaban almacenados previamente en el vector. ¿Cómo modificarías la implementación de este método para que se preservara el contenido?


Veamos a continuación la implementacón de los métodos de acceso:

~~~cpp
double& vector::at(size_t i)
{
	assert(i < sz_);

    return base_[i];
}

double vector::at(size_t i) const
{
	assert(i < sz_);

    return base_[i];
}
~~~

Como se puede observar, se hace referencia a la función `assert`. Esta función tiene como propósito efectuar una parada de la ejecución del programa en caso de que no se verifique la condición que se pasa como parámetro. Esta función de muy útil para verificar que los valores de determinadas variables, durante la ejecución del programa, debe cumplir ciertas condiciones. En caso de que no sea así, la ejecución se detiene, se muestra un mensaje de error indicando la línea de código en la que se ha producido el error de ejecución.

Si quiere ver cómo funciona, prueba a acceder a una posición del vector posterior al tamaño del mismo.

Los métodos de sobrecarga del operador `[]` hacen referencia a los métodos de acceso reseñados anteriormente.

~~~cpp
double& vector::operator[](size_t i)
{
    return at(i);
}

double vector::operator[](size_t i) const
{
    return at(i);
}
~~~


Los siguiente métodos de entrada salida tienen como propósito la escritura y la lectura, respectivamente, de un vector en/desde fichero.

~~~cpp
    std::ostream &vector::write(std::ostream &os) const
    {
        os << std::setw(8) << sz_ << std::endl;

        for (int i = 0; i < sz_; i++)
            os << std::setw(8) << std::fixed << std::setprecision(4) << base_[i] << " ";

        os << std::endl;
    }

    std::istream &vector::read(std::istream &is)
    {
        is >> sz_;

        resize(sz_);

        for (int i = 0; i < sz_; i++)
            is >> base_[i];
    }
~~~



## Actividades propuestas

1. Modifica la clase `vector` para que incluya, además de los constructores actuales, un constructor 

~~~cpp
	vector(int a, int b);
~~~
que permita indexar el vector en el rango [a, b]. Permitiendo accesos como éste:
~~~cpp
	vector a(-10, -1);

	a[-5] = 4;
~~~
:boom: Pista: Se deben cambiar los atributos, incluso de tipo de dato.

2. Modifica la clase `vector` para que el método `resize` preserve el contenido original del vector.

3. Modifica la clase `vector` para que almacene elementos de tipo entero.
