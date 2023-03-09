## Polymorphism Notes
1. For Best Practise:
   ````
   1. Always Make compiler Work for you, How?
        1.1 To make it give errors that hint you
   2.To Apply That:
        2.1 Use word Final to avoid 
            override function You don't override
        2.2 Use override word in child to make compiler Know that you want to
             use this function which is inherited from parent
        2.3 Always Type word virtual If it's virtual, Don't depend on compiler  and to make code friendly to read 
   ```` 
2. If Behavior change when data type change that's polymorphism, otherwise you can use templates
3. When You make an interface
   * Know that you must make it intuitve
   * You can't change it at all, because multiple projects are depending on it
   * You must provide so basic functions in the interface, by basic I mean the functions that guarnanteed no change in the future
4. In the market, it's better to depend on composition of interfaces instead of hirarcheal inheritance
5. It's always better to decrease inheritance and increase composition
6. If you write function of type:
   * **non virtual**--> means don't override, use this implementaiton
   * **virutual** --> it's ok to override or not if you want to keep using it
   * **pure virtual**--> means you must provide an overrider for child 
  
  