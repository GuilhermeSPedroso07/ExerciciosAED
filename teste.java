public class Animal {
    private int fome;
    private int sono;
    private int diasDeVida;
    
    public void Animal () {
        fome = 0;
        sono = 0;
        diasDeVida = 0;
    }
    
    abstract void fazerBarulho();
    
    public void comer () {
        fome--;
        sono++;
        
        if ( fome < 0 ) {
            fome = 0;
        }
    }
    
    public void dormir () {
        diasDeVida++;
        sono -= 5;
        
        if ( sono < 0 ) {
            sono = 0;
        }
    }
    
    public void vaguear () {
        fome++;
        sono++;
    }
    
}

public class Leao extends Animal {
    public void fazerBarulho () {
        System.out.print("Roar");
    }
    
    public void comer () {
        super.comer();
        super.comer();
    }
    
    public void printTudo() {
        System.out.print("" + this.fome);
        System.out.print("" + this.sono);
        System.out.print("" + this.diasDeVida);
    }
}

public class Main
{
	Animal novoAnimal = new Leao();
}
