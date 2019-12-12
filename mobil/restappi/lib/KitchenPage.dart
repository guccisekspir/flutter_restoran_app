import 'package:flutter/material.dart';
import 'package:restappi/main.dart';

class KitchenPage extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    return kitchenPageState();
  }
}

class kitchenPageState extends State {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return GridView.builder(
      gridDelegate:
      SliverGridDelegateWithFixedCrossAxisCount(crossAxisCount: 2),
      itemBuilder: (context, index) {
        return Stack(
          children: <Widget>[
            GestureDetector(
              onTap: () {
                Navigator.of(context).pop();
              },
              child: Container(
                padding: EdgeInsets.all(10.0),
                margin: EdgeInsets.all(10.0),
                height: 300,
                width: 300,
                decoration: BoxDecoration(
                    gradient: LinearGradient(
                        begin: Alignment.bottomLeft,
                        end: Alignment.topRight,
                        colors: [
                          Colors.blue,
                          Colors.black12
                        ]),
                    borderRadius: BorderRadius.circular(40)),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: <Widget>[
                    Text(
                      "Masa"
                    ),
                  ],
                ),
              ),
            ),
            Align(
              alignment: Alignment.bottomLeft,
              child: GestureDetector(
                onTap: () {
                  Navigator.of(context).pop();
                },
                child: Stack(
                  children: <Widget>[
                    CircleAvatar(
                      backgroundColor: Colors.black38,
                      radius: 30,
                    ),
                    Icon(
                      Icons.add_circle,
                      size: 60,
                      color: Colors.white70,
                    ),
                  ],
                ),
              ),
            )
          ],
        );
      },
      itemCount: 5,
    );
  }
}

