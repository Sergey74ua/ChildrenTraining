//JS-счетчик кликов на клиенте
var js_count = 0;
function JS_Click() {
    js_count++;
    document.getElementById("js_count").innerHTML = js_count;
};