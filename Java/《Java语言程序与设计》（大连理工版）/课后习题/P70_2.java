package 程序实践题;//(未优化)
abstract class Blank{
	protected String name;
	protected int account;
	public Blank(String IdName) {
		name=IdName;
	}
	protected abstract void show();
}

class Acc extends Blank{
	private int Idaccount;
	private int takein;
	private int takeout;
	
	public Acc(String IdName,int IdTakein,int IdTakeout) {
		super(IdName);
		takein =IdTakein;
		takeout=IdTakeout;
	}
	public void setTakein(int Idin) {
		takein=Idin ;
	}
	public int getTakein() {
		return takein;
	}
	public void setTakeout(int Idout) {
		takeout=Idout ;
	}
	public int getTakeout() {
		return takeout;
	}
	
	public int findAcc() {
		Idaccount=account+takein-takeout;
		return Idaccount;
	}
	public void show() {
		String massage ="******银行账户*****";
		massage+="\n账户名："+name;
		massage+="\n现有存款："+(takein-takeout);
		System.out.println(massage);
	}
}


public class P70_2 {
	public static void main(String[] args) {
		Acc c1=new Acc("tom",800,200);
		c1.show();
		}
}
