package charactor;

public class ADHero extends Hero {	//物理攻击英雄
	public ADHero(String name) {
		super(name);
	}

	public void attack() {
		System.out.println(name + " 进行了一次攻击 ，但是不确定打中谁了");
	}

	// 可变数量的参数
	public void attack(Hero... heros) {
		for (int i = 0; i < heros.length; i++) {
			System.out.println(name + " 攻击了 " + heros[i].name);

		}
	}

	public static void main(String[] args) {
		ADHero bh = new ADHero("赏金猎人");
		
		Hero h1 = new Hero("盖伦");
		Hero h2 = new Hero("提莫");

		bh.attack(h1);
		bh.attack(h1, h2);

	}

}
