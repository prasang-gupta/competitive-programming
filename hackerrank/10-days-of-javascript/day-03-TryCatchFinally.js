/*
 * Complete the reverseString function
 * Use console.log() to print to stdout.
 */
function reverseString(s) {
    var revs = "";
    try{
        revs = s.split("").reverse().join("");
    }
    catch (e){
        console.log(e.message);
    }
    finally{
        if (revs == ""){
            console.log(s);
        }
        else{
            console.log(revs);
        }
    }
}