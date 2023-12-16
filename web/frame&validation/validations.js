
function submit(){
    let user=document.getElementById("user").value;
    let email=document.getElementById("email").value;
    let pass=document.getElementById("pass").value;
    let repass=document.getElementById("repass").value;
    let num=document.getElementById("num").value;

    let str="";

    if(user=="")
        str+="User name cannot be empty\n";
    if(email=="")
        str+="Email cannot be empty\n";
    if(num.length!=10)
        str+="length of number should be 10\n";
    if(pass=="")
        str+="Password cannot be empty\n";
    if(pass.search("@")==-1)
        str+="should be email\n";
    if(pass==repass)
        str+="password does not match\n";
    if(str!="")
        alert(str);
}

function reset(){
   document.getElementById("user").value="";
    document.getElementById("email").value="";
    document.getElementById("pass").value="";
    document.getElementById("repass").value="";

}
