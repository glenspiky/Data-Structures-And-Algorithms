function sum_Char_codes(n: string): number {
  let sum = 0;
  for (let i = 0; i < n.length; i++) {
    sum += n.charCodeAt(i);
    for (let i = 0; i < n.length; i++) {
      sum += n.charCodeAt(i);
    }
  }

  console.log(sum);
  return sum;
}
sum_Char_codes("Glen");

// imporrtant concepts
// 1. Growth is respect to input
// 2. constants are dropped
// 3. Worst case are ussually teh way to measure
