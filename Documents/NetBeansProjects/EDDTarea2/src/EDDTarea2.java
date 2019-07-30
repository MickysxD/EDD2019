/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Micky
 */
public class EDDTarea2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Bolsa b = new Bolsa();
        Productos p;
        
        //validando metodo Vacia sin valores
        System.out.println(b.Vacia(b));
        
        //Agregando elementos de prueba
        for (int i = 0; i < 10; i++) {
            p = new Productos(i);
            b.Insertar(b, p);
        }
        
        //Monstando el contador
        System.out.println(b.conteo);
        
        p = b.primero;
        
        //imprecion en consola de valores en la lista
        for (int i = 0; i < b.Contar(); i++) {
            System.out.println(p.valor);
            p = p.siguiente;
        }
        
        //validando de nuevo el metodo vacia con valores dentro
        System.out.println(b.Vacia(b));
    }
    
    //Lista simple enlazada circular
    public static class Bolsa {
        Productos primero;
        int conteo;
        
        //Inicializa la bolsa vacia y con valores default
        public Bolsa() {
            this.primero = null;
            this.conteo = 0;
        }
        
        //Pide un parametro tipo Bolsa a la cual agregar un valor tipo Producto
        public void Insertar(Bolsa b, Productos p) {
            if (b.Contar() == 0) {
                b.primero = p;
                b.primero.siguiente = b.primero;
                conteo++;
            }else{
                Productos t = b.primero;
                for (int i = 1; i < b.Contar(); i++) {
                    t = t.siguiente;
                }
                p.siguiente = b.primero;
                t.siguiente = p;
                conteo++;
            }
        }
        
        //comprueba si la bolsa del parametro esta vacia
        public boolean Vacia(Bolsa b) {
            boolean v = false;
            if (b.Contar() == 0) {
                v = true;
                return v;
            }else{
                return v;
            }
        }
        
        //retorna la variable de el conteo de datos en la lista
        public int Contar() {
            return conteo;
        }
    }   
    
    //Nodo llamado productos para la bolsa
    public static class Productos {
        Productos siguiente;
        int valor;
        
        //inicializa el producto con valores por dafault
        public void Productos() {
            this.siguiente = null;
            this.valor = 0;
        }
        
        //inicializa el producto con valore del parametro
        public Productos(int v) {
            this.siguiente = null;
            this.valor = v;
        }
        
        public Productos getSiguiente() {
            return siguiente;
        }

        public void setSiguiente(Productos siguiente) {
            this.siguiente = siguiente;
        }

        public int getValor() {
            return valor;
        }

        public void setValor(int valor) {
            this.valor = valor;
        }
        
        
    
    }
}


