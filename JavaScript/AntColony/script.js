//Симулятор колонии муравьев

let listClass=['Ant', 'Model', 'View', 'Control', 'Main'];

for (let name of listClass) {
    let script=document.createElement('script');
    script.type='application/javascript';
    script.src='js/'+name+'.js';
    document.body.appendChild(script);
}