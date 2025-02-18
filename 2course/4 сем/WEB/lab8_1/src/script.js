function testFunc()
{
    document.getElementById('test').innerHTML += "все выполнилось";
    console.log("Nice");
}

document.addEventListener("DOMContentLoaded", function(event) 
{ 
    testFunc();
});
