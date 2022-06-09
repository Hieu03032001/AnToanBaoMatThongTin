//-----------------thuat toan----------------------------------------------------
// check so nguyen to
function IsPrime(a){
    if(a < 2)
        return false;
    var s = Math.floor(Math.sqrt(a));
    for(var i = 2; i <= s;i++)
        if(a % i == 0)
            return false;
    return true;
}
//mang nhi phan 1 so
function binaryNum(a){
    var arr = [];
    while (a > 0){
        arr.push(a%2);
        a = Math.floor(a/2);
    }
    return arr;
}

//binh phuong va nhan
function expmod(alpha, a, p){
    var arr = binaryNum(a);
    var beta = alpha%p;
    var c ;
    for(var i = arr.length-2 ; i >= 0 ; i--){
        if(arr[i] == 0){
            c = (beta*beta) %p;
        }
        else{
            c = (beta *beta * alpha)%p;
        }
        beta = c;
    }
    return c;
}
// tim modulo nghich dao: euclide
function Inverse(a,b){
    var q,r,y,y0,y1;
    y0=0, y1=1,d = b;
    while(a>0){
        q = Math.floor(b/a);
        r = b%a;
        if( r == 0)
            break;
        y = y0-q*y1;
        b=a;
        a=r;
        y0=y1;
        y1=y;
    }
    return y;
}

//chuyen mang kí tự sang mảng unicode
function convertUni(arrInput){
    arrUni = [];
    for(var index = 0; index < arrInput.length; index++)
        arrUni.push(arrInput.charCodeAt(index));
    return arrUni;
}
//chuyen mang sang string
function convertString(arrOut){
    arrString = [];
    for(var index = 0; index < arrOut.length; index++)
        arrString.push(String.fromCharCode(arrOut[index]));
    return arrString;
}
//hàm mã hóa
function MaHoa(){
    var p = document.getElementById("p").value;
    var alpha = document.getElementById("alpha").value;
    var a = document.getElementById("a").value;
    var banRo = document.getElementById("maHoa_banRo").value;
    var beta = expmod(alpha,a,p);
    arrBanRoUni = convertUni(banRo);
    arrBanMa = []
    var c1, c2,k;
    for(var index = 0 ; index < arrBanRoUni.length; index ++){
        k = Math.floor(Math.random()*p +1);
        c1 = expmod(alpha, k,p);
        c2 = (arrBanRoUni[index] * expmod(beta,k,p)) %p;
        arrBanMa.push(c1,c2);
    }
    //ban ma
    var banMa = [];
    banMa = convertString(arrBanMa).join('');
    return banMa;
}

// ham giai ma
function GiaiMa(){
    var p = document.getElementById("p").value;
    var a = document.getElementById("a").value;
    var c = document.getElementById("giaiMa_banMa").value;
    var arrBanMas = convertUni(c);
    var ArrgiaiMa = [];
    for(var i = 0; i < arrBanMas.length; ){
        //---------- dinh li nho fermat-------------------
        var k =expmod(arrBanMas[i],a,p);// k nho hon p
        var m = (expmod(k,p-2,p)* (arrBanMas[i+1])%p )%p;
        //---------------end------------------------------
        
        //---------euclide--------------------------------
        // var j = Inverse(k,p);
        // if(j < 0){
        //     j = j+p;
        // }
        // var m = ( j*arrBanMas[i+1])%p;
        // console.log(k,j,m);
        //----------------end----------------------------

        //var m = (expmod(arrBanMas[i],p-1-a,p) *(arrBanMas[i+1])%p )%p;
        
        ArrgiaiMa.push(m);
        i+=2;
    }
    var giaiMa = convertString(ArrgiaiMa).join(''); 
    return giaiMa;
}
//-----------------END thuat toan------------------------------------------------



//-------------------------button------------------------------------------------
// button tao khao cong khai
function create_key(){
    var p = document.getElementById("p").value;
    var alpha = document.getElementById("alpha").value;
    var a = document.getElementById("a").value;
    document.getElementById("beta").value = expmod(alpha,a,p);
}
//button ma hoa
function button_MaHoa(){   
    var p = document.getElementById("p").value;
    var alpha = document.getElementById("alpha").value;
    var a = document.getElementById("a").value;
    check_input();
    
    //xuat ban ma
    document.getElementById("beta").value = expmod(alpha,a,p);
    document.getElementById("maHoa_banMa").value = MaHoa();
}

//button giai ma
function button_GiaiMa(){
    var k = Inverse(30,101);
    console.log(k);
    document.getElementById("giaiMa_banRo").innerHTML = GiaiMa() ;
}
// button delete
function button_XoaBanRo(){
    document.getElementById("maHoa_banRo").value = "";
}
function button_XoaBanMa(){
    document.getElementById("giaiMa_banMa").value = "";
}
// button copy
function copy_banMa(){
    var s = document.getElementById("maHoa_banMa").value;
    document.getElementById("giaiMa_banMa").value = s;
}
// check input
function check_input(){
    var p = document.getElementById("p").value;
    var alpha = document.getElementById("alpha").value;
    var a = document.getElementById("a").value;
    var patt =/[^0-9]/;//regex

    // ----------------check p----------------------------------
    if(p == ""){
        document.getElementById("allert_p").innerText = "Khong duoc bo trong";
    }
    else{
        if(patt.test(p) == false){
            if(IsPrime(p) == false){
                document.getElementById("p").value ="";
                document.getElementById("allert_p").innerText ="p khong la so nguyen to";
            }
            else{
                document.getElementById("allert_p").innerText ="";
            }
        }
        else{
            document.getElementById("p").value ="";
            document.getElementById("allert_p").innerText ="nhap lai so p";
        }
    }
    //-----------end check p---------------------------------------


    // ----------------check alpha---------------------------------

    //xay dung ham kiem tra can nguyen thuy a cua p
    if( alpha == ""){
        document.getElementById("allert_alpha").innerText = "Khong duoc bo trong";
    }
    else{
        if(patt.test(p) == false){
            if(alpha> p){
                document.getElementById("alpha").value ="";
                document.getElementById("allert_alpha").innerText ="alpha nho hon p";
            }
            else{
                document.getElementById("allert_alpha").innerText ="";
            }
        }
        else{
            document.getElementById("alpha").value ="";
            document.getElementById("allert_alpha").innerText ="nhap lai so alpha";
        }
    }
    //-----------end check alpha---------------------------------------

    // ----------------check a-----------------------------------------

    //xay dung ham kiem tra can nguyen thuy a cua p
    if( alpha == ""){
        document.getElementById("allert_a").innerText = "Khong duoc bo trong";
    }
    else{
        if(patt.test(p) == false){
            if(alpha> p-1){
                document.getElementById("alpha").value ="";
                document.getElementById("allert_a").innerText ="a nho hon p-1";
            }
            else{
                document.getElementById("allert_a").innerText ="";
            }
        }
        else{
            document.getElementById("alpha").value ="";
            document.getElementById("allert_a").innerText ="nhap lai so a";
        }
    }
}
    //-----------end check a----------------------------------------------

    //-------------------------END button--------------------------------------------
    

//---------------------- read fie----------------------------------------------------
function readfileEncry(event){
    var file = event.target.files[0];
    var reader = new FileReader();
    reader.onload = function(e) {
        document.getElementById("maHoa_banRo").innerHTML = e.target.result;
    };
    reader.readAsText(file);
}

function readfileDecry(event){
    var file = event.target.files[0];
    var reader = new FileReader();
    reader.onload = function(e) {
        document.getElementById("giaiMa_banMa").innerHTML = e.target.result;
    };
    reader.readAsText(file);
}


