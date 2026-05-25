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
