function putDataInRes (e) {
    var btn = e.target || e.srcElement;
    document.getElementById('res').innerHTML += btn.innerHTML;
}

function clearRes (e) {
    document.getElementById('res').innerHTML = '';
}

function evaluate (e) {
    let s = document.getElementById('res').innerHTML;
    
    let re_nums = new RegExp(/[0-1]+/gm);
    let re_op = new RegExp(/[^0-1]/gm);
    let nums = s.match(re_nums);
    let op = s.match(re_op);
    
    let a = parseInt(nums[0], 2);
    let b = parseInt(nums[1], 2);
    
    let evalstring = a.toString() + op + b.toString();
    let ans = eval(evalstring);
    
    document.getElementById('res').innerHTML = ans.toString(2);
}

document.getElementById('btn0').addEventListener('click', putDataInRes);
document.getElementById('btn1').addEventListener('click', putDataInRes);
document.getElementById('btnSub').addEventListener('click', putDataInRes);
document.getElementById('btnSum').addEventListener('click', putDataInRes);
document.getElementById('btnMul').addEventListener('click', putDataInRes);
document.getElementById('btnDiv').addEventListener('click', putDataInRes);
document.getElementById('btnClr').addEventListener('click', clearRes);
document.getElementById('btnEql').addEventListener('click', evaluate);