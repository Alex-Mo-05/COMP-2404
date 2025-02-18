public class Customer {
    String name = "Bob";
    int age = 27;
    float money = 50.0f;
    boolean admitted = false;

    public Customer (String initName) {
        name = initName;
        age = 0;
        money = 0.0f;
        admitted = false;
    }

    public Customer (String initName, int initAge) {
        name = initName;
        age = initAge;
        money = 0.0f;
        admitted = false;
    }

    public Customer (String initName, int initAge, float initMoney) {
        name = initName;
        age = initAge;
        money = initMoney;
        admitted = false;
    }

    public Customer () {
        name = "Name";
        age = 50;
        money = 100f;
        admitted = false;
    }

    public float computeFee() {
        float fee;
        if (age >= 65){
            fee = (float)12.75 * (float)0.50;
        } else if (age >= 18) {
            fee = 12.75f;
        } else if (age <= 3) {
            fee = 0;
        } else {
            fee = 8.50f;
        }
        return fee;
    }

    public boolean spend(float amount){
        if (amount < money && amount > 0){
            money -= amount;
            return true;
        }
        return false;
    }

    public boolean hasMoreMoneyThan(Customer c){
        if (money > c.money){
            return true;
        }
        return false;
    }

    public void payAdmission(){
        if (spend(computeFee())){
            admitted = true;
        }
    }

    public String toString(){
        if (admitted){
            return ("Customer " + name + ": a " + age + " year old with $" + money + " who has been admitted");
        }
        return ("Customer " + name + ": a " + age + " year old with $" + money + " who has not been admitted");

    }

}
