#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, const char * argv[]) {

    // Load image
    Mat image = imread("image.jpg", IMREAD_COLOR);

    // Check for errors
    if (image.empty()) {
        std::cout << "Could not read image file." << std::endl;
        return 1;
    }

    // Display image
    namedWindow("Original Image", WINDOW_NORMAL);
    imshow("Original Image", image);
    waitKey(0);

    // Apply filter
    Mat filteredImage;
    cv::GaussianBlur(image, filteredImage, Size(3,3), 0);

    // Display filtered image
    namedWindow("Filtered Image", WINDOW_NORMAL);
    imshow("Filtered Image", filteredImage);
    waitKey(0);

    // Save filtered image
    imwrite("filtered_image.jpg", filteredImage);

    return 0;
}
