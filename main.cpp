#include "qsfmlcanvas.h"
#include <QApplication>
#include <QFrame>

class MyCanvas : public QSFMLCanvas
{
public :

    MyCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size) :
    QSFMLCanvas(Parent, Position, Size)
    , myImage()
    , mySprite()
    , myClock()
    {

    }

private :

    void OnInit()
    {
        // Load the image
        myImage.loadFromFile("img/killer.png");

        // Setup the sprite
        mySprite.setTexture(myImage);
        mySprite.setOrigin(mySprite.getGlobalBounds().width/2.f, mySprite.getGlobalBounds().height/2.f);
        mySprite.setPosition((sf::Vector2f)getSize()/2.f);
    }

    void OnUpdate()
    {
        // Clear screen
        clear(sf::Color(0, 128, 0));

        // Rotate the sprite
        mySprite.rotate(myClock.restart().asSeconds() * 10.f);

        // Draw it
        draw(mySprite);
    }

    sf::Texture  myImage;
    sf::Sprite mySprite;
    sf::Clock myClock;
};

int main(int argc, char **argv)
{
    QApplication App(argc, argv);

    // Create the main frame
    QFrame* MainFrame = new QFrame;
    MainFrame->setWindowTitle("Qt SFML");
    MainFrame->resize(400, 400);
    MainFrame->show();

    // Create a SFML view inside the main frame
    MyCanvas* SFMLView = new MyCanvas(MainFrame, QPoint(20, 20), QSize(360, 360));
    SFMLView->show();

    return App.exec();
}
