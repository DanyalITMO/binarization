#include <QApplication>
#include<QHBoxLayout>
#include<QLabel>
#include<iostream>
#include<QImage>

QImage brightness(const QImage& imgOrig)
{
    QImage imgTemp = imgOrig;
    int  nHeight = imgTemp.height();
    int nWidth  = imgTemp.width();

    QRgb* matrix  = new QRgb [nHeight * nWidth];
    QRgb** tempLine = new  QRgb* [nHeight];

    for (qint32 y = 0; y < nHeight; ++y)
    {
        tempLine[y] = reinterpret_cast<QRgb*>(imgTemp.scanLine(y));

        for (qint32 x = 0; x < nWidth; ++x)
             *(matrix + y*nWidth + x)  = (qRed(tempLine[y][x]) + qGreen(tempLine[y][x]) + qBlue(tempLine[y][x]))  > 150 ? qRgb(255, 255 ,255): qRgb(0, 0 ,0);

    }

      QImage img((uchar*)matrix, nWidth, nHeight, QImage::Format_ARGB32);

      return img;
}


int main(int argc, char *argv[])
{

        QApplication app(argc, argv);
        QImage       img("//home//danek//temp.png");
        QImage  result = brightness(img);
        result.save("//home//danek//result.png");

        QWidget      wgt;
        QHBoxLayout* phbx = new QHBoxLayout;
        phbx->setMargin(0);
        phbx->setSpacing(0);

        QLabel* plbl = new QLabel;
            plbl->setFixedSize(img.size());
            plbl->setPixmap(QPixmap::fromImage(brightness(img)));
            phbx->addWidget(plbl);

        wgt.setLayout(phbx);
        wgt.show();
        return app.exec();


}

