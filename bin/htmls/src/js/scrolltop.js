$(document).ready(function(){
	//1.���Ƚ�#goTopBtn����
	$("#goTopBtn").hide();

	//2.����������¼�������ʱ����
	$(window).scroll(function(){
		//����������λ�ô��ھඥ��0��������ʱ�����ض�����ť���֣�������ʧ
		if ($(window).scrollTop()>0){
			$("#goTopBtn").fadeIn(1500);
			}
		else{
			$("#goTopBtn").fadeOut(1500);
			}
	});
	
	//3.��������ض�����ť�󣬻ص�ҳ�涥��λ��
	$("#goTopBtn").click(function(){
		$('body,html').animate({scrollTop:0},1000);
	});
});
