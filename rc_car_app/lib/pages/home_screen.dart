import 'package:flutter/material.dart';

class HomeScreen extends StatelessWidget {
  static const routeName = '/homeScreen';

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Text(
          "RC Controller App",
          style: TextStyle(
            color: Colors.green,
            fontSize: 32,
          ),
        ),
      ),
    );
  }
}
