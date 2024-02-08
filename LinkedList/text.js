const calculate = (arrOfNumbers) => {
    //write your code here
      let sum = 0 ;
      arrOfNumbers.forEach((number) => sum+= (number * number));
      return sum/arrOfNumbers.length;
    }
   console.log(calculate([4 , 6 , 10 ,12]));