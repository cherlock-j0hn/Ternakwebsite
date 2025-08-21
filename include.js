function loadHTML(id, file) {
  fetch(file)
    .then(response => {
      if (!response.ok) throw new Error("Could not load " + file);
      return response.text();
    })
    .then(data => {
      document.getElementById(id).innerHTML = data;
    })
    .catch(error => console.error(error));
}

// Load header and footer when the page loads
document.addEventListener("DOMContentLoaded", function() {
  loadHTML("header-placeholder", "header.html");
  loadHTML("footer-placeholder", "footer.html");
});

const selectedBox = document.getElementById('selected-box');
const optionsContainer = document.getElementById('options-container');
const checkboxes = optionsContainer.querySelectorAll('input[type="checkbox"]');

// Contact Page

// Toggle options on click - contact form
selectedBox.addEventListener('click', () => {
  optionsContainer.style.display = optionsContainer.style.display === 'block' ? 'none' : 'block';
});

// Update selected values - contact form
checkboxes.forEach(checkbox => {
  checkbox.addEventListener('change', () => {
    const selected = Array.from(checkboxes)
                          .filter(cb => cb.checked)
                          .map(cb => cb.value);
    selectedBox.textContent = selected.length ? selected.join(', ') : 'Choose services';
  });
});

// Close dropdown if clicked outside - contact form
document.addEventListener('click', (event) => {
  if (!event.target.closest('.multi-select')) {
    optionsContainer.style.display = 'none';
  }
});


// About page

// Trigger animations on scroll  - about page
/*
 window.addEventListener('scroll', () => {
    const sections = document.querySelectorAll('.experience-section, .our-services-section');
    sections.forEach(section => {
        const sectionPosition = section.getBoundingClientRect().top;
        const screenPosition = window.innerHeight / 1.1;
        if (sectionPosition < screenPosition && !section.classList.contains('animate')) {
            section.classList.add('animate');
            const boxes = section.querySelectorAll('.service-box');
            boxes.forEach(box => box.classList.add('animate'));
        }
    });
});
*/
    