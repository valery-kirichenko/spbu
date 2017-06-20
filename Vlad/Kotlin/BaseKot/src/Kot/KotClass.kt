package Kot

fun main(args: Array<String>) {
    val stringArrTemplate = arrayOf("Steve", "Greg", "Wanderer")
    val intArrTemplate = intArrayOf(5,6,9,7,8,9,5,4,4,4)
    val greeter = Greeter(4, 5)
    greeter.sayHello(stringArrTemplate)
    greeter.printDigits()
    println(greeter.sum(intArrTemplate))
    println(greeter.division(8,6))
}
class Greeter(val a: Int, val b: Int) {

    val oneMillion = 123.3f

    fun sayHello(a : Array<String>) {
        for (name in a) {
            print("Hello, $name!\n")
        }
    }

    fun printDigits() {
        for (digit in listOf(a,b)) {
            println(digit)
        }
    }

    fun sum(array : IntArray) : Int {
        var sum : Int = 0
        for (digit in array) {
            sum += digit
        }
        return sum
    }

    fun division(a : Int, b : Int) : Double {
        if (b == 0) throw IllegalArgumentException("0 is not allowed for division!")
        return (a.toDouble() / b.toDouble())
    }
}