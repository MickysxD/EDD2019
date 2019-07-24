package eddtarea1;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.Scanner;

public class EDDTarea1 {

    public static Scanner s = new Scanner(System.in);
    
    public static void main(String[] args) {
        menu();
    }
    
    public static void menu(){
        System.out.println("1. Dia de la semana");
        System.out.println("2. Numeros primos");
        System.out.println("3. Salir");
        System.out.println("Ingrese el numero de la accion a realizar");
        
        int r = s.nextInt();
        
        if (r == 1) {
            int a,m,d;
            System.out.println("Ingrese el año");
            a = s.nextInt();
            System.out.println("Ingrese el mes");
            m = s.nextInt();
            System.out.println("Ingrese el dia");
            d = s.nextInt();
            Fecha(a,m,d);
            menu();
        }else if (r == 2) {
            int p;
            System.out.println("Ingrese el año");
            p = s.nextInt();
            NumerosP(p);
            menu();
        }else if (r == 3) {
            System.exit(0);
        }
    }
    
    public static void Fecha(int anio, int mes, int dia){
        String f = "";
        int n=0;
        
        Calendar c = Calendar.getInstance();
        c.set(anio, mes, dia);
        n = c.get(Calendar.DAY_OF_WEEK)-2;
        System.out.println(c.get(Calendar.DAY_OF_WEEK)-2);
        switch (n){
            case 1: 
                f = "Domingo";
                break;
            case 2: 
                f = "Lunes";
                break;
            case 3: 
                f = "Martes";
                break;
            case 4: 
                f = "Miercoles";
                break;
            case 5: 
                f = "Jueves";
                break;
            case 6: 
                f = "Viernes";
                break;
            case 7: 
                f = "Sabado";
                break;
        }
        
        System.out.println(f);
    
    }
    
    public static void NumerosP(int valor){
        List<Object> primos = new ArrayList<Object>();
        
        if (valor >= 2) {
            for (int i = 2; i <= valor; i++) {
                primos.add(i);
            }
            
            for (int i = 2; i <= valor; i++) {
                for (int j = 3; j < valor; j++) {
                    int n = j*i;
                    primos.remove(n);
                }
                if (i*i > valor) {
                    break;
                }
            }
        }
        System.out.println(primos.toString());
    }
}
