import 'package:flutter/material.dart';
import 'package:restappi/main.dart';



class KitchenPage extends StatefulWidget{
  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    return kitchenPageState();
  }


}


class kitchenPageState extends State{
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Container(
      decoration: BoxDecoration(
        gradient: LinearGradient(
          colors: [
            renkMutfakSari,
            Color.fromARGB(255, 107, 29, 29)
          ]
        )
      ),
    );
  }
}